#include "stdafx.h"
#include "MyFileservice.h"
#include "../../dao/myfile/MyFileDAO.h"
#include <SnowFlake.h>
#include "../../domain/do/file/file_attachmentDO.h"
#include "../../domain/do/file/file_attachment2DO.h"
#include "../../domain/do/folder/file_folderDO.h"

//删除
bool MyFileservice::removeData(string id)
{
	MyFileDAO dao;
	return dao.deleteById(id) == 1;
}

//用于下载接口，根据id查询xstorage文件下载路径，
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

//根据id查name
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

//上传文件，文件信息保存在数据库中
uint64_t MyFileservice::saveData(const MyfileDTO::Wrapper& dto)
{
	//雪花算法生产xid
	SnowFlake sf(1, 1);
	unsigned int a = sf.nextId();
	std::string str = std::to_string(a);
	dto->xid = str;
	// 组装DO数据
	MyFileDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, xid, XcreateTime, xcreateTime, XupdateTime, xupdateTime, Xextension, xextension, Xlength, xlength, XdeepPath, xdeepPath, \
		Xfolder, xfolder, XlastUpdatePerson, xlastUpdatePerson, XlastUpdateTime, xlastUpdateTime, Xname, xname, Xperson, xperson, Xstorage, xstorage)
		// 执行数据添加
		MyFileDAO dao;
	return dao.insert(data);
}
//替换文件，文件信息保存在数据库中
uint64_t MyFileservice::ModifyData(const MyfileDTO::Wrapper& dto)
{
	// 组装DO数据
	MyFileDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, xid, XcreateTime, xcreateTime, XupdateTime, xupdateTime, Xextension, xextension, Xlength, xlength, XdeepPath, xdeepPath, \
		XlastUpdatePerson, xlastUpdatePerson, XlastUpdateTime, xlastUpdateTime, Xname, xname, Xperson, xperson, Xstorage, xstorage)
		// 执行数据修改
		MyFileDAO dao;
	return dao.update(data);
}

//上传成功，插入日志
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

//删除成功，插入日志
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
//	// 组装DO数据
//	SampleDO data;
//	// 	data.setId(dto->id.getValue(0));
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
//		// 执行数据修改
//		SampleDAO dao;
//	return dao.update(data) == 1;
//}

//Yu 分页查询
FolderQueryPageDTO::Wrapper MyFileservice::listAll(const FileInfoQUERY::Wrapper& query, const string& id)
{
	// 构建返回对象
	auto pages = FolderQueryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MyFileDAO dao;
	list<folder_queryDO> result;
	//传入xid为空，查询根目录下xsuperior，xfolder为null的记录
	if (id=="{xid}") {
		uint64_t count = dao.count_null(query, id);
		if (count <= 0)
		{
			return pages;
		}
		// 分页查询数据
		pages->total = count;
		pages->calcPages();
		result = dao.selectWithPage_null(query, id);
	}
	//传入xid不为空，查询根目录下xsuperior，xfolder为xid的记录
	else{
	uint64_t count = dao.count(query, id);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	 result = dao.selectWithPage(query, id);
	}
	// 将DO转换成DTO
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

//保存数据(添加目录)
uint64_t MyFileservice::saveData(const FolderAddDTO::Wrapper& dto)
{
	//雪花算法生成xid
	SnowFlake sf(1, 2);
	unsigned int a = sf.nextId();
	std::string str = std::to_string(a);
	dto->xid = str;
	// 使用 SimpleDateTimeFormat 生成创建时间和更新时间
	std::string createTime = SimpleDateTimeFormat::format(); // 获取创建时间
	dto->xcreateTime = SimpleDateTimeFormat::format(); // 设置创建时间
	dto->xupdateTime = SimpleDateTimeFormat::format(); // 设置更新时间

	// 将创建时间格式转换为 YmdHMS 格式
	std::string formattedTime = createTime;
	// 移除日期中的 -
	formattedTime.erase(std::remove(formattedTime.begin(), formattedTime.end(), '-'), formattedTime.end());
	// 移除时间中的空格
	formattedTime.erase(std::remove(formattedTime.begin(), formattedTime.end(), ' '), formattedTime.end());
	// 移除时间中的 :
	formattedTime.erase(std::remove(formattedTime.begin(), formattedTime.end(), ':'), formattedTime.end());

	// 生成 xsequence，由格式化的创建时间和 xid 拼接而成
	dto->xsequence = formattedTime + dto->xid;

	// 组装DO数据
	file_folderDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, xid, Xname, xname, Xsuperior, xsuperior, Xperson, xperson,
		XcreateTime, xcreateTime, XupdateTime, xupdateTime, Xsequence, xsequence);

	// 执行数据添加
	MyFileDAO dao;
	return dao.insert(data);
}

