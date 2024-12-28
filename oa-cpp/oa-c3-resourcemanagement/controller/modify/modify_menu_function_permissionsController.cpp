#include "stdafx.h"
#include "modify_menu_function_permissionsController.h"
#include "../../service/modify/modify_menulist_fpService.h"

#include "../ApiDeclarativeServicesHelper.h"



StringJsonVO::Wrapper modify_menu_function_permissionsController::execModifymenupermissions(const modify_menulist_fpDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (dto->role_id->empty())
	{
		jvo->init(String("-1"), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	modify_menulist_fpService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->role_id);
	}
	else
	{
		jvo->fail(dto->menuList);
	}

	// 响应结果
	return jvo;
}