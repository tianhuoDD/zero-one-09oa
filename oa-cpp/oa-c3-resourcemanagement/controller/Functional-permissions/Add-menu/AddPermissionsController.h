#pragma once
#ifndef _ADDMENUCONTROLLER_H_
#define _ADDMENUCONTROLLER_H_

//#include "domain/vo/BaseJsonVO.h"//��������ģ�͵�basejson
#include "../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../../domain/vo/Functional-permissions/Add-menu/AddmenuVO.h"
#include "../../../domain/dto/Functional-permissions/Add-menu/AddmenuDTO.h"
//#include "domain/GlobalInclude.h"
#include "../../../domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(ApiController)//oatp�е�apiController

class AddPermissionsController :public oatpp::web::server::api::ApiController//�̳�aipController
{
    //����������������
    API_ACCESS_DECLARE(AddPermissionsController);
public: //����ӿ�/�˵�
  
    // 3.1 ���������ӿ�����
    ENDPOINT_INFO(AddmenuPermissions) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Functional-permissions.Add-menu.post.summary"));//���Ĵʵ���Ѱ��
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        //���Ӧ���Լ�дһ��VO��Ӧ��ʽΪ���Ȩ�޳ɹ�
        //Ҫ����VO��ͷ�ļ�
        API_DEF_ADD_RSP_JSON_WRAPPER(AddmenuJsonVO);
    }
    ///////////////////////////////
    //���������ӿڴ���
    ENDPOINT(API_M_POST, "resource-management/functional-permissions/add-menu", AddmenuPermissions, BODY_DTO(AddmenuDTO::Wrapper, dto),API_HANDLER_AUTH_PARAME) {
        //��������                                                        //BODY_DTO����Ҫ�Լ�д���������ģ����
        API_HANDLER_RESP_VO(execAddmenu(dto));
      
    }

private://����ӿ�ִ�к���
    
    AddmenuJsonVO::Wrapper execAddmenu(const AddmenuDTO::Wrapper& dto);
};
#include OATPP_CODEGEN_END(ApiController)
#endif//!_TESTCONTROLLER_H_
