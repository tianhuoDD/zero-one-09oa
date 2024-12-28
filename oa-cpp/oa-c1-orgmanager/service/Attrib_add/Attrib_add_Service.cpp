
#include "stdafx.h"
#include "Attrib_add_Service.h"
#include "../../dao/Attrib_add/Attrib_add_DAO.h"
#include "../../domain/do/Attrib_add/Attrib_add_DO.h"

//����id�Ƕ�����
uint64_t Attrib_add_Service::select_id(const Attrib_add_DTO::Wrapper& dto)
{
	Attrib_add_DO data_id_name;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_id_name, dto, Xid, xid, Xname, xname);
	Attrib_add_DAO dao;
	return dao.select(data_id_name);
}
//add
//uint64_t Attrib_add_Service::saveData1(const Attrib_add_DTO::Wrapper& dto)//dtoת����do
//{
//	// ��װDO����
//	Attrib_add_DO data;
//
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Shuxing, shuxing);//
//	// ִ���������
//	Attrib_add_DAO dao;
//	return dao.insert1(data);
//}
uint64_t Attrib_add_Service::saveData2(const Attrib_add_DTO::Wrapper& dto)//dtoת����do
{
	// ��װDO����
	Attrib_add_DO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, xid, Xname, xname, XdistributeFactor, xdistributeFactor, XdistinguishedName, xdistinguishedName, Xdescription, xdescription);
	// ִ���������
	Attrib_add_DAO dao;
	return dao.insert2(data);
}