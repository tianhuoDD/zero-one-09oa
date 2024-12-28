
#include "stdafx.h"
#include <iostream>
#include "MyfileController.h"
#include "../../service/myfile/MyFileservice.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"


//	Xhaizi

//上传文件  返回新增日志的xid
StringJsonVO::Wrapper MyfileController::execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 解析数据
	/* TODO: 解析的数据具体逻辑，需要根据你的业务需求来，下面是使用示例而已。 */
	/* 获取表单数据 */

	/* 打印表单数据 [注释]*/
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "xfolder", xfolder);
	if (xfolder) OATPP_LOGD("Multipart", "xfolder='%s'", xfolder.getValue({}).c_str());

	//* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	string fn = "";
	string suffix = "";
	string Xxstorage = "";
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		printf("%s\n", filename.c_str());
		fn = filename;
		/* 测试上传到FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// 获取文件后缀名
		suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		Xxstorage = downloadUrl;
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
	}
	//将数据封装到DTO里面
	auto dto = MyfileDTO::createShared();
	//文件格式【已完成】
	dto->xextension = suffix;
	//父文件夹（前端传入）【已完成】
	dto->xfolder = xfolder.getValue({}).c_str();
	//dto->xdeepPath = xdeepPath.getValue({}).c_str();
	//文件大小和名称【已完成】
	dto->xname = fn;
	dto->xlength = file->size();
	dto->xstorage = Xxstorage;
	printf("%d", dto->xlength.getValue(1));
	//权限校验给【已完成】
	//payload.setXsequence("abc");
	dto->xperson = payload.getXsequence();
	dto->xlastUpdatePerson = payload.getXsequence();

	auto jvo = StringJsonVO::createShared();
	MyFileservice service;

	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
		return jvo;
	}

	//数据库新增日志
	auto ddto = FileLogDTO::createShared();
	ddto->file_attachment_id = dto->xid;
	ddto->xFromPerson = dto->xperson;
	ddto->xToPerson = payload.getXsequence();
	cout << ddto->file_attachment_id.getValue("") << " " << ddto->xFromPerson.getValue("") << " " << ddto->xToPerson.getValue("") << " ";
	uint64_t idd = service.insertLogData(ddto);
	auto jvoo = StringJsonVO::createShared();
	if (idd > 0) {
		jvoo->success(ddto->xid);
	}
	else
	{
		jvoo->fail(ddto->xid);
		return jvoo;
	}
	return jvo;
}

//下载文件 返回下载路径
StringJsonVO::Wrapper MyfileController::execDownloadFile(const String& xid)
{
	auto jvo = StringJsonVO::createShared();
	if (!xid)
	{
		jvo->init(String("-1"), RS_PARAMS_INVALID);
		return jvo;
	}
	cout << xid.getValue("") << endl;
	// 定义一个Service
	MyFileservice service;
	// 查询数据
	auto result = service.QuaryStoragebyId(xid);
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	result = urlPrefix + result;
	// 响应结果
	
	jvo->success(result);
	return jvo;
}

//删除文件  返回日志的xid
StringJsonVO::Wrapper MyfileController::execRemoveSample(const String& xid, const PayloadDTO& payload)
{  
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 定义一个Service
	MyFileservice service;
	string storage = service.QuaryStoragebyId(xid);
	// 执行数据删除
	if (service.removeData(xid)) {
		/*	deleteFile*/
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		bool a = true;
		a = dfs.deleteFile(storage);
		jvo->success(xid);
	}
	else
	{
		jvo->fail(xid);
	}

	//数据库新增删除日志
	auto ddto = FileLogDTO::createShared();
	//将xid、xFromPerson、xToPerson数据提取到日志
	ddto->file_attachment_id = xid;
	//payload.setXsequence("abc");
	ddto->xFromPerson = payload.getXsequence();
	ddto->xToPerson = payload.getXsequence();
	uint64_t idd = service.insertLogDeleteData(ddto);
	if (idd > 0) {
		jvo->success(ddto->xid);
		return jvo;
	}
	else
	{
		jvo->fail(ddto->xid);
		return jvo;
	}

	// 响应结果
	return jvo;
}

//替换文件,返回替换文件的xid
StringJsonVO::Wrapper MyfileController::execModifySample(std::shared_ptr<IncomingRequest> request, const  PayloadDTO& payload)
{

	// 1 初始化，前端获取xid，xfolder
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "xid", xid);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "xfolder", xfolder);
	if (xid) OATPP_LOGD("Multipart", "xid='%s'", xid.getValue({}).c_str());
	if (xfolder) OATPP_LOGD("Multipart", "xfolder='%s'", xfolder.getValue({}).c_str());
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);


	//先删除文件
	MyFileservice service;
	string xxid = xid.getValue({}).c_str();
	string storage = service.QuaryStoragebyId(xxid);
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	bool a = true;
	a = dfs.deleteFile(storage);

	//文件名称//文件后缀名	//文件路径
	string fn = ""; string suffix = ""; string Xxstorage = "";
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		printf("%s\n", filename.c_str());
		fn = filename;
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// 获取文件后缀名
		suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}

		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		Xxstorage = downloadUrl;
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
	}

	//将数据封装到DTO里面
	auto dto = MyfileDTO::createShared();
	//文件格式【已完成】
	dto->xextension = suffix;
	//id（前端传入）【已完成】
	dto->xid = xid.getValue({}).c_str();
	//文件大小和名称【已完成】
	dto->xname = fn;
	dto->xlength = file->size();
	dto->xstorage = Xxstorage;
	//权限校验给【已完成】
	//payload.setXsequence("abc");
	dto->xperson = payload.getXsequence();
	dto->xlastUpdatePerson = payload.getXsequence();

	auto jvo = StringJsonVO::createShared();

	// 执行数据新增
	uint64_t id = service.ModifyData(dto);
	if (id > 0) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
		return jvo;
	}

	return jvo;
}


//	Yu
//, const PayloadDTO& payload, const String& id
FileInfoPageJsonVO::Wrapper MyfileController::executeQueryFileInfo(const FileInfoQUERY::Wrapper& query)
{
	//string xid=URIUtil::urlDecode(id.getValue(""));
	// 定义一个Service
	MyFileservice service;
	string xid = query->xid;
	//// 查询数据
	auto result = service.listAll(query, xid);
	// 响应结果
	auto jvo = FileInfoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

Uint64JsonVO::Wrapper MyfileController::executeAddFileInfo(const FolderAddDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->xname || !dto->xperson)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->xname->empty() || dto->xperson->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	

	// 定义一个Service
	MyFileservice service;
	// 执行目录新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//jvo->success(UInt64(id));
	////数据库新增日志
	//auto ddto = FileLogDTO::createShared();
	//ddto->file_attachment_id = dto->xid;
	//ddto->xFromPerson = dto->xperson;
	//ddto->xToPerson = payload.getUsername();
	//cout << ddto->file_attachment_id.getValue("") << " " << ddto->xFromPerson.getValue("") << " " << ddto->xToPerson.getValue("") << " ";
	//uint64_t idd = service.insertLogData(ddto);
	//auto jvoo = StringJsonVO::createShared();
	//if (idd > 0) {
	//	jvoo->success(ddto->xid);
	//}
	//else
	//{
	//	jvoo->fail(ddto->xid);
	//	return jvoo;
	//}
	//响应结果
	return jvo;
}
