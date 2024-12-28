#include"stdafx.h"
#include"UserLoginConfigurationController.h"
#include "../../service/userloginconfiguration/UserLoginConfigurationService.h"
#include "../ApiDeclarativeServicesHelper.h"
UserLoginConfigurationJsonVO::Wrapper UserLoginConfigurationController::executeQueryUserLoginConfiguration(const String& username)
{
	// 定义一个Service
	UserLoginConfigurationService service;
	// 查询数据
	auto result = service.listAll(username);
	// 响应结果
	auto jvo = UserLoginConfigurationJsonVO::createShared();
	jvo->success(result);
	return jvo;
	// 
	//测试
	//return{};

}

//UserLoginConfigurationDTO::Wrapper 等价于  oatpp::Object<UserLoginConfigurationDTO>
StringJsonVO::Wrapper UserLoginConfigurationController::executeModifyUserLoginConfiguration(const UserLoginConfigurationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->id||!dto->username||dto->loginattempts >=5)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	UserLoginConfigurationService service;

	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->username);
	}
	else
	{
		jvo->fail(dto->username);
	}
	// 响应结果
	return jvo;
}