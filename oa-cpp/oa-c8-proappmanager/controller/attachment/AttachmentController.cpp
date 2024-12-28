#include "stdafx.h"
#include <iostream>
#include "AttachmentController.h"



// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"



AttachmentListJsonVO::Wrapper AttachmentController::execQueryAttachmentList(const oatpp::String& applicationID) {
	// ����һ��Service
	AttachmentService service;
	// ��ѯ����
	auto result = service.listAll(applicationID.getValue(""));
	// ��Ӧ���
	auto jvo = AttachmentListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
AttachmentDetailJsonVO::Wrapper AttachmentController::execQueryAttachmentDetail(const oatpp::String& attachmentID) {
	// ����һ��Service
	AttachmentService service;
	// ��ѯ����
	auto result = service.Detail(attachmentID.getValue(""));
	// ��Ӧ���
	auto jvo = AttachmentDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


StringJsonVO::Wrapper AttachmentController::execAddAttachement(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload) {
	AttachmentService service;
	auto jvo = StringJsonVO::createShared();
	//return StringJsonVO::createShared();
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);
	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	API_MULTIPART_CONFIG_MEMO(reader, "alias", -1);
	API_MULTIPART_CONFIG_MEMO(reader, "application", -1);
	API_MULTIPART_CONFIG_MEMO(reader, "description", -1);
	API_MULTIPART_CONFIG_MEMO(reader, "fileName", -1);
	API_MULTIPART_CONFIG_MEMO(reader, "name", -1);

	// 3 ��ȡ����
	request->transferBody(&reader);

	// 4 ��������
	auto dto = AttachmentOperateDTO::createShared();

	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "alias", alias);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "application", application);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "description", description);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "fileName", fileName);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "name", name);

	if (dto->application == nullptr || dto->application->empty()) {
		jvo->fail("application is empty.");
		return jvo;
	}

	dto->application = application;
	dto->description = description;
	dto->alias = alias;
	dto->fileName = fileName;
	dto->name = name;

	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file) {
		/* �ļ����� */
		string filename = partfile->getFilename().getValue("");
		if (dto->name->empty()) {
			dto->name = filename;
		}
		dto->length = file->size();

		/* �ϴ���FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// ��ȡ�ļ���׺��
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos) {
			suffix = filename.substr(pos + 1);
		}
		// �ϴ��ļ�
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		dto->data = String(downloadUrl);
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
		auto result = service.saveFile(dto, payload);
		jvo->success(String(result));
	} else jvo->fail(String("err. file is empty."));
	return jvo;
}

StringJsonVO::Wrapper AttachmentController::execUpdateAttachment(const AttachmentOperateDTO::Wrapper dto, const PayloadDTO& payload) {
	AttachmentService service;
	if (dto->id == nullptr || dto->id->empty()) {
		auto jvo = StringJsonVO::createShared();
		jvo->fail("id is empty.");
		return jvo;
	}
	auto result = service.updateFile(dto, payload);
	auto jvo = StringJsonVO::createShared();
	if (result) jvo->success("Update successfully.");
	else jvo->fail("Update failed.");
	return jvo;
}

StringJsonVO::Wrapper AttachmentController::execDeleteAttachment(const String attachmentId) {
	AttachmentService service;
	auto jvo = StringJsonVO::createShared();
	auto result = service.deleteFile(attachmentId.getValue(""));
	if (!result.empty()) {
		// ɾ��fastdfs�ļ�
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		bool isDel = dfs.deleteFile(result);
		if (isDel) jvo->success("Delete successfully."); 
		else jvo->fail("Delete failed.");
	} else jvo->fail("Delete failed.");
	return jvo;
}
