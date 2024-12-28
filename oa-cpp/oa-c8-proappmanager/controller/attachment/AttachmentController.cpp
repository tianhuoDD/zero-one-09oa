#include "stdafx.h"
#include <iostream>
#include "AttachmentController.h"



// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"



AttachmentListJsonVO::Wrapper AttachmentController::execQueryAttachmentList(const oatpp::String& applicationID) {
	// 定义一个Service
	AttachmentService service;
	// 查询数据
	auto result = service.listAll(applicationID.getValue(""));
	// 响应结果
	auto jvo = AttachmentListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
AttachmentDetailJsonVO::Wrapper AttachmentController::execQueryAttachmentDetail(const oatpp::String& attachmentID) {
	// 定义一个Service
	AttachmentService service;
	// 查询数据
	auto result = service.Detail(attachmentID.getValue(""));
	// 响应结果
	auto jvo = AttachmentDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


StringJsonVO::Wrapper AttachmentController::execAddAttachement(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload) {
	AttachmentService service;
	auto jvo = StringJsonVO::createShared();
	//return StringJsonVO::createShared();
	// 1 初始化
	API_MULTIPART_INIT(container, reader);
	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	API_MULTIPART_CONFIG_MEMO(reader, "alias", -1);
	API_MULTIPART_CONFIG_MEMO(reader, "application", -1);
	API_MULTIPART_CONFIG_MEMO(reader, "description", -1);
	API_MULTIPART_CONFIG_MEMO(reader, "fileName", -1);
	API_MULTIPART_CONFIG_MEMO(reader, "name", -1);

	// 3 读取数据
	request->transferBody(&reader);

	// 4 解析数据
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

	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file) {
		/* 文件名称 */
		string filename = partfile->getFilename().getValue("");
		if (dto->name->empty()) {
			dto->name = filename;
		}
		dto->length = file->size();

		/* 上传到FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos) {
			suffix = filename.substr(pos + 1);
		}
		// 上传文件
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
		// 删除fastdfs文件
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		bool isDel = dfs.deleteFile(result);
		if (isDel) jvo->success("Delete successfully."); 
		else jvo->fail("Delete failed.");
	} else jvo->fail("Delete failed.");
	return jvo;
}
