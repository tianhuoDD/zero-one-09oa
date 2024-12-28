#include"stdafx.h"
#include"PersonPwdInfoController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/PersonPwd/PersonPwdInfoService.h"
#include "../../service/UserPasswordService/UserPasswordService.h"
PersonPwdInfoJsonVO::Wrapper PersonPwdInfoController::executeQueryPersonPwdInfo(const String& id)
{
	// 定义一个Service
	PersonPwdInfoService service;
	// 查询数据
	auto result = service.ListAll(id);
	//响应结果
	auto jvo = PersonPwdInfoJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper PersonPwdInfoController::executeSaveUserPasswordSettings(const UserPasswordDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // 定义返回数据对象
    auto jvo = StringJsonVO::createShared();

    // 定义一个Service对象
    UserPasswordService service;
    bool success = true;

    // 校验并执行各个设置的保存操作
    success &= service.modifyUserPasswordSettings(dto);

    // 如果保存操作失败
    if (!success) {
        jvo->init("error", RS_PARAMS_INVALID);
        return jvo;
    }

    // 根据操作结果设置响应状态
    jvo->success("success");

    // 响应结果
    return jvo;
}
