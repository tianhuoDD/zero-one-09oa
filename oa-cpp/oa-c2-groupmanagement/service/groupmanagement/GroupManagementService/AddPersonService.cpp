/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 25�� ������ 19:40:34 CST
*/
#include "stdafx.h"
#include "AddPersonService.h"
#include "dao/GroupManagement/GroupManagementDAO/AddPersonDAO.h"

AddPersonDTO::Wrapper AddPersonService::saveData(const AddPersonDTO::Wrapper& dto)
{
	// ��װDO����
	OrgGroupPersonlistDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Group_xid, GROUP_XID, Xperson_list, xpersonList, Xorder_column, xorderColumn)
		// ִ���������
		AddPersonDAO dao;
	uint64_t res = dao.insert(data);
	AddPersonDTO::Wrapper ap_dto;
	if (res) {
		ap_dto = dto;
		return ap_dto;
	}
	return {};
}
