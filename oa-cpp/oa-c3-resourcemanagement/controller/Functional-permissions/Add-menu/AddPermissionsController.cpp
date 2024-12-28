#include "stdafx.h"
#include "AddPermissionsController.h"
#include "../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../lib-oatpp/include/domain/vo/JsonVO.h"
#include "../../../controller/ApiDeclarativeServicesHelper.h"
#include "../../../service/Functional-permissions/Add-menu/AddmenuService.h"


AddmenuJsonVO::Wrapper AddPermissionsController:: execAddmenu(const AddmenuDTO::Wrapper& dto)
{
	auto jvo = AddmenuJsonVO::createShared();
	auto vodto = AddmenuVO::createShared();
	// 参数校验
    //感觉得对输入的id和功能是否存在进行校验，这里没有关联其他表就先不管了
	//需要用到人员表，就是人的编号，还需要菜单表判断输入的菜单权限是否存在
	if (dto->role_id->empty() || dto->permissions->empty())
	{
		
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	
	
	// 定义一个Service
	 //感觉得对输入的id和功能是否存在进行校验，这里没有关联其他表就先不管了
	//需要用到人员表，就是人的编号，还需要菜单表判断输入的菜单权限是否存在
	AddmenuService service;
	if (service.selectDatabyrole_id(dto)<=0)
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	if (service.selectDatabypermissions(dto) <= 0)
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	
	
	if (service.selectDataisexist(dto) > 0)
	{
		jvo->init(vodto, RS_PARAMS_INVALID);
		return jvo;
	}
	// 执行数据新增
	//用这个包裹着传过来的数据

	uint64_t id = service.saveData(dto);

	if (id == 0)
	{
		vodto->role_id = dto->role_id;
		vodto->permissions = dto->permissions;
		jvo->success(vodto);

	}
	else
	{
		jvo->fail(vodto);
	}
	
	
	//响应结果
	
	return jvo;
	
}
