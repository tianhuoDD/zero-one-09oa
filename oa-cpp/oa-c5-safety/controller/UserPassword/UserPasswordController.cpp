#include "stdafx.h"
#include "UserPasswordController.h"
#include "../../service/UserPasswordService/UserPasswordService.h"

StringJsonVO::Wrapper UserPasswordController::executeSaveUserPasswordSettings(const UserPasswordDTO::Wrapper& dto, const PayloadDTO& payload)
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
