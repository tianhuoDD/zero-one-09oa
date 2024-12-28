#pragma once
#ifndef _DELETECONTROLLER_H_
#define _DELETECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"//��������ģ�͵�basejson
#include "../../../domain/GlobalInclude.h"
#include "../../../domain/dto/Functional-permissions/Delete-menu/DeletemenuDTO.h"
#include "../../../domain/vo/Functional-permissions/Delete-menu/DeletemenuVO.h"
#include "oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)//oatp�е�apiController

class DeletePermissionsController :public oatpp::web::server::api::ApiController//�̳�aipController
{
    //����������������
    API_ACCESS_DECLARE(DeletePermissionsController);
public: //����ӿ�/�˵�
    // 3.1 ����ɾ���ӿ�����
    ENDPOINT_INFO(DeletemenuPermissions) {
        // �������ͷ��������Լ���Ȩ֧��
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Functional-permissions.Delete-menu.delete.summary"));
        // ��������·������˵��
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(DeletemenuJsonVO);
    }
    ///////////////////////////////
    // 3.2 ����ɾ���ӿڴ���
    
    ENDPOINT(API_M_DEL, "resource-management/functional-permissions/delete-menu", DeletemenuPermissions, BODY_DTO(DeletemenuDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        //��������                                                        //BODY_DTO����Ҫ�Լ�д���������ģ����
        API_HANDLER_RESP_VO(execDeletemenu(dto));

    }
private://����ӿ�ִ�к���
   
    DeletemenuJsonVO::Wrapper execDeletemenu(const DeletemenuDTO::Wrapper& dto);
};
#include OATPP_CODEGEN_END(ApiController)
#endif//!_TESTCONTROLLER_H_

