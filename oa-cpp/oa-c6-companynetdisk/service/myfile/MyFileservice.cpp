#include "stdafx.h"
#include "MyFileservice.h"
#include "../../dao/myfile/MyFileDAO.h"
#include <SnowFlake.h>
#include "../../domain/do/file/file_attachmentDO.h"
#include "../../domain/do/file/file_attachment2DO.h"
#include "../../domain/do/folder/file_folderDO.h"

//ɾ��
bool MyFileservice::removeData(string id)
{
	MyFileDAO dao;
	return dao.deleteById(id) == 1;
}

//�������ؽӿڣ�����id��ѯxstorage�ļ�����·����
string MyFileservice::QuaryStoragebyId(string xid)
{
	MyFileDAO dao;
	list<MyFileDO> result = dao.selectStoragebyxid(xid);
	auto dto = MyfileDTO::createShared();
	MyFileDO sub = result.front();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xstorage, Xstorage);
	string resultt;
	for (MyFileDO sub : result)
	{
		resultt = dto->xstorage;
	}
	return resultt;
}

//����id��name
string MyFileservice::QuaryNamebyId(string xid)
{
	MyFileDAO dao;
	list<MyFileDO> result = dao.selectNamebyxid(xid);
	auto dto = MyfileDTO::createShared();
	MyFileDO sub = result.front();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xname, Xname);
	string resultt;
	for (MyFileDO sub : result)
	{
		resultt = dto->xname;
	}
	return resultt;
}

//�ϴ��ļ����ļ���Ϣ���������ݿ���
uint64_t MyFileservice::saveData(const MyfileDTO::Wrapper& dto)
{
	//ѩ���㷨����xid
	SnowFlake sf(1, 1);
	unsigned int a = sf.nextId();
	std::string str = std::to_string(a);
	dto->xid = str;
	// ��װDO����
	MyFileDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, xid, XcreateTime, xcreateTime, XupdateTime, xupdateTime, Xextension, xextension, Xlength, xlength, XdeepPath, xdeepPath, \
		Xfolder, xfolder, XlastUpdatePerson, xlastUpdatePerson, XlastUpdateTime, xlastUpdateTime, Xname, xname, Xperson, xperson, Xstorage, xstorage)
		// ִ���������
		MyFileDAO dao;
	return dao.insert(data);
}
//�滻�ļ����ļ���Ϣ���������ݿ���
uint64_t MyFileservice::ModifyData(const MyfileDTO::Wrapper& dto)
{
	// ��װDO����
	MyFileDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, xid, XcreateTime, xcreateTime, XupdateTime, xupdateTime, Xextension, xextension, Xlength, xlength, XdeepPath, xdeepPath, \
		XlastUpdatePerson, xlastUpdatePerson, XlastUpdateTime, xlastUpdateTime, Xname, xname, Xperson, xperson, Xstorage, xstorage)
		// ִ�������޸�
		MyFileDAO dao;
	return dao.update(data);
}

//�ϴ��ɹ���������־
uint64_t MyFileservice::insertLogData(const FileLogDTO::Wrapper& ddto) {
	SnowFlake sff(1, 1);
	unsigned int aa = sff.nextId();
	std::string str = std::to_string(aa);
	ddto->xid = str;

	FileLogDO dataa;
	//dataa.setXid(ddto->xid.getValue(""));
	//dataa.setXOperationType(ddto->xOperationType.getValue(0));
	//dataa.setFile_attachment_id(ddto->file_attachment_id.getValue(""));
	//dataa.setXFromPerson(ddto->xFromPerson.getValue(""));
	////dataa.setXToPerson(ddto->xToPerson.getValue(""));
	//dataa.setXOperationTime(ddto->xOperationTime.getValue(""));

	ZO_STAR_DOMAIN_DTO_TO_DO(dataa, ddto, Xid, xid, XOperationType, xOperationType, \
		XFromPerson, xFromPerson, XToPerson, xToPerson, XOperationTime, xOperationTime, File_attachment_id, file_attachment_id)

		MyFileDAO daoo;

	return daoo.insertlog(dataa);
}

//ɾ���ɹ���������־
uint64_t MyFileservice::insertLogDeleteData(const FileLogDTO::Wrapper& ddto) {
	SnowFlake sff(1, 1);
	unsigned int aa = sff.nextId();
	std::string str = std::to_string(aa);
	ddto->xid = str;

	FileLogDO dataa;

	ZO_STAR_DOMAIN_DTO_TO_DO(dataa, ddto, Xid, xid, XOperationType, xOperationType, \
		XFromPerson, xFromPerson, XToPerson, xToPerson, XOperationTime, xOperationTime, File_attachment_id, file_attachment_id)

		MyFileDAO daoo;

	return daoo.insertDeletelog(dataa);
}


//bool MyFileservice::updateData(const MyfileDTO::Wrapper& dto)
//{
//	// ��װDO����
//	SampleDO data;
//	// 	data.setId(dto->id.getValue(0));
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
//		// ִ�������޸�
//		SampleDAO dao;
//	return dao.update(data) == 1;
//}

//Yu ��ҳ��ѯ
FolderQueryPageDTO::Wrapper MyFileservice::listAll(const FileInfoQUERY::Wrapper& query, const string& id)
{
	// �������ض���
	auto pages = FolderQueryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	MyFileDAO dao;
	list<folder_queryDO> result;
	//����xidΪ�գ���ѯ��Ŀ¼��xsuperior��xfolderΪnull�ļ�¼
	if (id=="{xid}") {
		uint64_t count = dao.count_null(query, id);
		if (count <= 0)
		{
			return pages;
		}
		// ��ҳ��ѯ����
		pages->total = count;
		pages->calcPages();
		result = dao.selectWithPage_null(query, id);
	}
	//����xid��Ϊ�գ���ѯ��Ŀ¼��xsuperior��xfolderΪxid�ļ�¼
	else{
	uint64_t count = dao.count(query, id);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	 result = dao.selectWithPage(query, id);
	}
	// ��DOת����DTO
	for (folder_queryDO sub : result)
	{
		auto dto = FolderQueryDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		dto->xid = sub.getXid();
		//dto->xdistributeFactor = sub.getattachmet2_XdistributeFactor();
		dto->xcreateTime = sub.getXcreateTime();
		dto->xsequence = sub.getXsequence();
		dto->xupdateTime = sub.getXupdateTime();;
		dto->xdeepPath = sub.getXdeepPath();
		dto->xextension = sub.getXextension();
		//dto->xfolder = sub.getXfolder();
		dto->xLastUpdatePerson = sub.getXlastUpdatePerson();
		dto->xLastUpdateTime = sub.getXlastUpdateTime();
		dto->xlength = sub.getXlength();
		dto->xname = sub.getXname();
		dto->xperson = sub.getXperson();
		dto->xstorage = sub.getXstorage();
		dto->folder_xid = sub.getfolder_Xid();
		dto->folder_xcreateTime = sub.getfolder_XcreateTime();
		dto->folder_xsequence = sub.getfolder_Xsequence();
		dto->folder_xupdateTime = sub.getfolder_XupdateTime();
		dto->folder_xname = sub.getfolder_Xname();
		dto->folder_xperson = sub.getfolder_Xperson();
		pages->addData(dto);
	}
	return pages;
}

//��������(���Ŀ¼)
uint64_t MyFileservice::saveData(const FolderAddDTO::Wrapper& dto)
{
	//ѩ���㷨����xid
	SnowFlake sf(1, 2);
	unsigned int a = sf.nextId();
	std::string str = std::to_string(a);
	dto->xid = str;
	// ʹ�� SimpleDateTimeFormat ���ɴ���ʱ��͸���ʱ��
	std::string createTime = SimpleDateTimeFormat::format(); // ��ȡ����ʱ��
	dto->xcreateTime = SimpleDateTimeFormat::format(); // ���ô���ʱ��
	dto->xupdateTime = SimpleDateTimeFormat::format(); // ���ø���ʱ��

	// ������ʱ���ʽת��Ϊ YmdHMS ��ʽ
	std::string formattedTime = createTime;
	// �Ƴ������е� -
	formattedTime.erase(std::remove(formattedTime.begin(), formattedTime.end(), '-'), formattedTime.end());
	// �Ƴ�ʱ���еĿո�
	formattedTime.erase(std::remove(formattedTime.begin(), formattedTime.end(), ' '), formattedTime.end());
	// �Ƴ�ʱ���е� :
	formattedTime.erase(std::remove(formattedTime.begin(), formattedTime.end(), ':'), formattedTime.end());

	// ���� xsequence���ɸ�ʽ���Ĵ���ʱ��� xid ƴ�Ӷ���
	dto->xsequence = formattedTime + dto->xid;

	// ��װDO����
	file_folderDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, xid, Xname, xname, Xsuperior, xsuperior, Xperson, xperson,
		XcreateTime, xcreateTime, XupdateTime, xupdateTime, Xsequence, xsequence);

	// ִ���������
	MyFileDAO dao;
	return dao.insert(data);
}

