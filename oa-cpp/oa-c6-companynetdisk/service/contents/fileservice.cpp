#include "stdafx.h"
#include "fileservice.h"
#include "../../dao/deletecontents/deletefileDAO.h"

bool FileService::updateContents(const DdeleteDTO::Wrapper& dto)
{
	// ��װDO����
	file_deleteDO data;
	//	data.setXid(dto->xid.getValue(0));
   // 	data.setName(dto->name.getValue(""));
   // 	data.setSex(dto->sex.getValue(""));
   // 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xname, xname, Xid, xid);
	// ִ�������޸�
	deletefileDAO dao;
	return dao.update(data) == 1;
}