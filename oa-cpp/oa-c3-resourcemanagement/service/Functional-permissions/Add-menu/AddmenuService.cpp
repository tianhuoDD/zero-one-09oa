#include "stdafx.h"
#include "AddmenuService.h"
#include "../../../domain/dto/Functional-permissions/Add-menu/AddmenuDTO.h"
#include "../../../domain/do/Function-permissions/Org_role_menulistDO.h"
#include "../../../dao/Functional-permissions/Add-menu/AddmenuDAO.h"
#include "../../../domain/vo/Functional-permissions/Add-menu/AddmenuVO.h"

//�����dto�еĸ���װ����DO
uint64_t AddmenuService::saveData(const AddmenuDTO::Wrapper& dto)
{
	// ��װDO����
	Org_role_menulistDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,role_Id, role_id,Menulist, permissions)
		//Ȼ���DOͨ��dao���ݸ����ݿ�
		// ִ���������
	AddmenuDAO dao;
	return dao.insert(data);
}
uint64_t AddmenuService::selectDatabyrole_id(const AddmenuDTO::Wrapper& dto)
{
	Org_role_menulistDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, role_Id, role_id, Menulist, permissions);
	AddmenuDAO dao;
    return dao.selectbyrole_id(data);




}
uint64_t AddmenuService::selectDatabypermissions(const AddmenuDTO::Wrapper& dto)
{
	Org_role_menulistDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Menulist, permissions);
	AddmenuDAO dao;
	return dao.selectbypermissions(data);




}

uint64_t AddmenuService::selectDataisexist(const AddmenuDTO::Wrapper& dto)
{
	Org_role_menulistDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, role_Id, role_id, Menulist, permissions);
	AddmenuDAO dao;
	return dao.selectisexist(data);
}
