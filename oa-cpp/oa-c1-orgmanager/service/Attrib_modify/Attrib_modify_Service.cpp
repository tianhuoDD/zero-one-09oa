
#include "stdafx.h"
#include "Attrib_modify_Service.h"
#include "../../dao/Attrib_modify/Attrib_modify_DAO.h"
#include "../../domain/do/Attrib_modify/Attrib_modify_DO.h"


uint64_t Attrib_modify_Service::select_id(const Attrib_modify_DTO::Wrapper& dto)
{
	Attrib_modify_DO data_id_name;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_id_name, dto, Xid, xid, XdistinguishedName_pre, xdistinguishedName_pre);
	Attrib_modify_DAO dao;
	return dao.select(data_id_name);
}

//modifiy
bool Attrib_modify_Service::updateData(const Attrib_modify_DTO::Wrapper& dto)
{
	// 组装DO数据
	Attrib_modify_DO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, xid, XdistinguishedName_pre, xdistinguishedName_pre, XdistinguishedName_last, xdistinguishedName_last, XdistributeFactor, xdistributeFactor, Xdescription, xdescription);
	// 执行数据修改
	Attrib_modify_DAO dao;
	return dao.update(data) == 1;
}