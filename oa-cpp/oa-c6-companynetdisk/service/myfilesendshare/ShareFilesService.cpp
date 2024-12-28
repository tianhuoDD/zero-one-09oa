#include "stdafx.h"
#include "ShareFilesService.h"
#include "../../dao/myfilesendshare/ShareFilesDAO.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include <SnowFlake.h>


uint64_t ShareFilesService::saveData(const ShareFilesDTO::Wrapper& dto)
{
	// 组装DO数据
	file_attachment_sharelistDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, attachment_xid, ATTACHMENT_XID, XshareList, xshareList, XorderColumn, xorderColumn)
		// 执行数据添加
		ShareFilesDAO dao;
	return dao.insert(data);
}
uint64_t ShareFilesService::insertShareLog(const FileLogDTO::Wrapper& ddto) {
	SnowFlake sff(1, 1);
	unsigned int aa = sff.nextId();
	std::string str = std::to_string(aa);
	ddto->xid = str;

	FileLogDO dataa;

	ZO_STAR_DOMAIN_DTO_TO_DO(dataa, ddto, Xid, xid, XOperationType, xOperationType, \
		XFromPerson, xFromPerson, XToPerson, xToPerson, XOperationTime, xOperationTime, File_attachment_id, file_attachment_id)

		ShareFilesDAO daoo;

	return daoo.insertsharelog(dataa);
}

