#include "stdafx.h"
#include "modify_menu_function_permissionsController.h"
#include "../../service/modify/modify_menulist_fpService.h"

#include "../ApiDeclarativeServicesHelper.h"



StringJsonVO::Wrapper modify_menu_function_permissionsController::execModifymenupermissions(const modify_menulist_fpDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (dto->role_id->empty())
	{
		jvo->init(String("-1"), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	modify_menulist_fpService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->role_id);
	}
	else
	{
		jvo->fail(dto->menuList);
	}

	// ��Ӧ���
	return jvo;
}