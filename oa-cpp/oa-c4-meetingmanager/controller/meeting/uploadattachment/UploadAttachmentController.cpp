#include "stdafx.h"
#include <iostream>
#include "UploadAttachmentController.h"
#include "../../../service/Meeting/uploadattachment/UploadAttachmentService.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
// 雪花算法需要导入的头
#include "SnowFlake.h"

StringJsonVO::Wrapper UploadAttachmentController::execUploadMeetingFile(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 定义文件传输对象
	auto dto = UploadAttachmentDTO::createShared();
	
	// 初始化读取器
	API_MULTIPART_INIT(container, reader);
	// 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	// 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	// 解析数据
	/* 获取表单数据 */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "xmeeting", xmeeting);
	API_MULTIPART_PARSE_FORM_FIELD_BOO(container, "xsummary", xsummary);
	/* 打印表单数据 */
	if (xmeeting) OATPP_LOGD("Multipart", "xmeeting='%s'", xmeeting.getValue({}).c_str());
	if (xsummary) OATPP_LOGD("Multipart", "xsummary=%b", xsummary.getValue({}));

	// 参数校验
	// 非空校验
	if (!xmeeting)
	{
		jvo->init("Params can't be null!", RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if ((xsummary != false && xsummary != true) || xmeeting->empty())
	{
		jvo->init("Params invalid!", RS_PARAMS_INVALID);
		return jvo;
	}

	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());

		/* 测试上传到FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);

		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}

		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		string loadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "load url='%s'", loadUrl.c_str());		

		// 获取当前时间字符串
		string datetime_format1 = SimpleDateTimeFormat::format();
		string datetime_format2 = SimpleDateTimeFormat::format("%Y%m%d%H%M%S");

		// 生成一个xid
		SnowFlake sf(4, 6);
		
		// 更新文件传输对象dto
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

	// 定义一个Service
	UploadAttachmentService service;
	// 执行数据修改
	if (service.saveData(dto)) {
		jvo->success("Succeed to save to mysql!");
	}
	else
	{
		jvo->fail("Failed to save to mysql!");
	}

	// 响应结果	
	jvo->success("Upload succeed!");
	return jvo;
}
