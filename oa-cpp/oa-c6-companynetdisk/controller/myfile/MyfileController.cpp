
#include "stdafx.h"
#include <iostream>
#include "MyfileController.h"
#include "../../service/myfile/MyFileservice.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"


//	Xhaizi

//�ϴ��ļ�  ����������־��xid
StringJsonVO::Wrapper MyfileController::execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 ��������
	/* TODO: ���������ݾ����߼�����Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	/* ��ȡ������ */

	/* ��ӡ������ [ע��]*/
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "xfolder", xfolder);
	if (xfolder) OATPP_LOGD("Multipart", "xfolder='%s'", xfolder.getValue({}).c_str());

	//* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	string fn = "";
	string suffix = "";
	string Xxstorage = "";
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		printf("%s\n", filename.c_str());
		fn = filename;
		/* �����ϴ���FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// ��ȡ�ļ���׺��
		suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// �ϴ��ļ�
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		Xxstorage = downloadUrl;
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
	}
	//�����ݷ�װ��DTO����
	auto dto = MyfileDTO::createShared();
	//�ļ���ʽ������ɡ�
	dto->xextension = suffix;
	//���ļ��У�ǰ�˴��룩������ɡ�
	dto->xfolder = xfolder.getValue({}).c_str();
	//dto->xdeepPath = xdeepPath.getValue({}).c_str();
	//�ļ���С�����ơ�����ɡ�
	dto->xname = fn;
	dto->xlength = file->size();
	dto->xstorage = Xxstorage;
	printf("%d", dto->xlength.getValue(1));
	//Ȩ��У���������ɡ�
	//payload.setXsequence("abc");
	dto->xperson = payload.getXsequence();
	dto->xlastUpdatePerson = payload.getXsequence();

	auto jvo = StringJsonVO::createShared();
	MyFileservice service;

	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
		return jvo;
	}

	//���ݿ�������־
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

//�����ļ� ��������·��
StringJsonVO::Wrapper MyfileController::execDownloadFile(const String& xid)
{
	auto jvo = StringJsonVO::createShared();
	if (!xid)
	{
		jvo->init(String("-1"), RS_PARAMS_INVALID);
		return jvo;
	}
	cout << xid.getValue("") << endl;
	// ����һ��Service
	MyFileservice service;
	// ��ѯ����
	auto result = service.QuaryStoragebyId(xid);
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	result = urlPrefix + result;
	// ��Ӧ���
	
	jvo->success(result);
	return jvo;
}

//ɾ���ļ�  ������־��xid
StringJsonVO::Wrapper MyfileController::execRemoveSample(const String& xid, const PayloadDTO& payload)
{  
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����һ��Service
	MyFileservice service;
	string storage = service.QuaryStoragebyId(xid);
	// ִ������ɾ��
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

	//���ݿ�����ɾ����־
	auto ddto = FileLogDTO::createShared();
	//��xid��xFromPerson��xToPerson������ȡ����־
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

	// ��Ӧ���
	return jvo;
}

//�滻�ļ�,�����滻�ļ���xid
StringJsonVO::Wrapper MyfileController::execModifySample(std::shared_ptr<IncomingRequest> request, const  PayloadDTO& payload)
{

	// 1 ��ʼ����ǰ�˻�ȡxid��xfolder
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "xid", xid);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "xfolder", xfolder);
	if (xid) OATPP_LOGD("Multipart", "xid='%s'", xid.getValue({}).c_str());
	if (xfolder) OATPP_LOGD("Multipart", "xfolder='%s'", xfolder.getValue({}).c_str());
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);


	//��ɾ���ļ�
	MyFileservice service;
	string xxid = xid.getValue({}).c_str();
	string storage = service.QuaryStoragebyId(xxid);
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	bool a = true;
	a = dfs.deleteFile(storage);

	//�ļ�����//�ļ���׺��	//�ļ�·��
	string fn = ""; string suffix = ""; string Xxstorage = "";
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		printf("%s\n", filename.c_str());
		fn = filename;
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// ��ȡ�ļ���׺��
		suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}

		// �ϴ��ļ�
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		Xxstorage = downloadUrl;
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
	}

	//�����ݷ�װ��DTO����
	auto dto = MyfileDTO::createShared();
	//�ļ���ʽ������ɡ�
	dto->xextension = suffix;
	//id��ǰ�˴��룩������ɡ�
	dto->xid = xid.getValue({}).c_str();
	//�ļ���С�����ơ�����ɡ�
	dto->xname = fn;
	dto->xlength = file->size();
	dto->xstorage = Xxstorage;
	//Ȩ��У���������ɡ�
	//payload.setXsequence("abc");
	dto->xperson = payload.getXsequence();
	dto->xlastUpdatePerson = payload.getXsequence();

	auto jvo = StringJsonVO::createShared();

	// ִ����������
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
	// ����һ��Service
	MyFileservice service;
	string xid = query->xid;
	//// ��ѯ����
	auto result = service.listAll(query, xid);
	// ��Ӧ���
	auto jvo = FileInfoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

Uint64JsonVO::Wrapper MyfileController::executeAddFileInfo(const FolderAddDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->xname || !dto->xperson)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->xname->empty() || dto->xperson->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	

	// ����һ��Service
	MyFileservice service;
	// ִ��Ŀ¼����
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//jvo->success(UInt64(id));
	////���ݿ�������־
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
	//��Ӧ���
	return jvo;
}
