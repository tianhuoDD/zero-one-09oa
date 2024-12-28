#include "stdafx.h"
#include <iostream>
#include "UploadAttachmentController.h"
#include "../../../service/Meeting/uploadattachment/UploadAttachmentService.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
// ѩ���㷨��Ҫ�����ͷ
#include "SnowFlake.h"

StringJsonVO::Wrapper UploadAttachmentController::execUploadMeetingFile(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// �����ļ��������
	auto dto = UploadAttachmentDTO::createShared();
	
	// ��ʼ����ȡ��
	API_MULTIPART_INIT(container, reader);
	// ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	// ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	// ��������
	/* ��ȡ������ */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "xmeeting", xmeeting);
	API_MULTIPART_PARSE_FORM_FIELD_BOO(container, "xsummary", xsummary);
	/* ��ӡ������ */
	if (xmeeting) OATPP_LOGD("Multipart", "xmeeting='%s'", xmeeting.getValue({}).c_str());
	if (xsummary) OATPP_LOGD("Multipart", "xsummary=%b", xsummary.getValue({}));

	// ����У��
	// �ǿ�У��
	if (!xmeeting)
	{
		jvo->init("Params can't be null!", RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if ((xsummary != false && xsummary != true) || xmeeting->empty())
	{
		jvo->init("Params invalid!", RS_PARAMS_INVALID);
		return jvo;
	}

	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());

		/* �����ϴ���FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);

		// ��ȡ�ļ���׺��
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}

		// �ϴ��ļ�
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		string loadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "load url='%s'", loadUrl.c_str());		

		// ��ȡ��ǰʱ���ַ���
		string datetime_format1 = SimpleDateTimeFormat::format();
		string datetime_format2 = SimpleDateTimeFormat::format("%Y%m%d%H%M%S");

		// ����һ��xid
		SnowFlake sf(4, 6);
		
		// �����ļ��������dto
		dto->xid = to_string(sf.nextId());
		dto->xcreateTime = datetime_format1;
		dto->xsequence = datetime_format2 + dto->xid;
		dto->xupdateTime = datetime_format1;
		dto->xdeepPath = 0;
		dto->xextension = suffix;
		dto->xlastUpdatePerson = payload.getUsername();
		dto->xlastUpdateTime = datetime_format1;
		dto->xlength = file->size();
		dto->xmeeting = xmeeting;
		dto->xname = filename;
		dto->xstorage = downloadUrl;
		dto->xsummary = xsummary;
	}

	// ����һ��Service
	UploadAttachmentService service;
	// ִ�������޸�
	if (service.saveData(dto)) {
		jvo->success("Succeed to save to mysql!");
	}
	else
	{
		jvo->fail("Failed to save to mysql!");
	}

	// ��Ӧ���	
	jvo->success("Upload succeed!");
	return jvo;
}
