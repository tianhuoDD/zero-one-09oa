#include "stdafx.h"
#include "DeletePermissionsController.h"
#include "../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../lib-oatpp/include/domain/vo/JsonVO.h"
#include "../../../service/Functional-permissions/Delete-menu/DeletemenuService.h"

DeletemenuJsonVO::Wrapper DeletePermissionsController:: execDeletemenu(const DeletemenuDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = DeletemenuJsonVO::createShared();
	auto vodto =DeletemenuVO::createShared();
	
	// 参数校验
	if (dto->role_id->empty() || dto->permissions->empty())
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	// 定义一个Service
	//判断想要删除的值是否存在
	DeletemenuService service;
	uint64_t count = service.selectData(dto);
	if (count <= 0)
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	
	// 执行数据删除
	if (service.removeData(dto)>0) {
		vodto->role_id = dto->role_id;
		auto permissionslist = dto->permissions;
	vodto->permissions= oatpp::List<String>::createShared(); // 创建一个新的列表
		for (const auto& permission : *permissionslist)
		{
			vodto->permissions->push_back(permission);
			
		}
		jvo->success(vodto);
	}
	else
	{
		jvo->fail(vodto);
	}
	// 响应结果
	return jvo;
	
}