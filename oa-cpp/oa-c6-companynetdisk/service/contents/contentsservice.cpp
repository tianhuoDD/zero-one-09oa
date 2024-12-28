
#include "stdafx.h"
#include "contentsservice.h"
#include "../../dao/deletecontents/deletecontentsDAO.h"

bool ContentsService::removeContents(string xid)
{
	contentsDAO dao;
	return dao.deleteById(xid) == 1;
}
//bool updateContents(const CdeleteDTO::Wrapper& dto);
bool ContentsService::updateContents(const CdeleteDTO::Wrapper& dto)
{
	// 组装DO数据
	file_folderDO data;
	//	data.setXid(dto->xid.getValue(0));
   // 	data.setName(dto->name.getValue(""));
   // 	data.setSex(dto->sex.getValue(""));
   // 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xname, xname, Xid, xid)
		// 执行数据修改
		contentsDAO dao;
	return dao.update(data) == 1;
}