#include "stdafx.h"
#include "UserPasswordController.h"
#include "../../service/UserPasswordService/UserPasswordService.h"

StringJsonVO::Wrapper UserPasswordController::executeSaveUserPasswordSettings(const UserPasswordDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // ���巵�����ݶ���
    auto jvo = StringJsonVO::createShared();

    // ����һ��Service����
    UserPasswordService service;
    bool success = true;

    // У�鲢ִ�и������õı������
    success &= service.modifyUserPasswordSettings(dto);

    // ����������ʧ��
    if (!success) {
        jvo->init("error", RS_PARAMS_INVALID);
        return jvo;
    }

    // ���ݲ������������Ӧ״̬
    jvo->success("success");

    // ��Ӧ���
    return jvo;
}
