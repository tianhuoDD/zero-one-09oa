#pragma once
#ifndef PERSON_ATTRIBUTE_CONTROLLER_H
#define PERSON_ATTRIBUTE_CONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/PersonAttribute/PersonAttributeVO.h"
#include "domain/dto/PersonAttribute/PersonAttributeDTO.h"
#include "domain/query/PersonAttributeQuery/PersonAttributeQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class PersonAttributeController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(PersonAttributeController);
public:


    // 3.1 定义路径查询接口描述
    ENDPOINT_INFO(queryPersonAttribute) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Personattribute.query.summary"));
        API_DEF_ADD_AUTH(); // 添加身份验证
        API_DEF_ADD_RSP_JSON_WRAPPER(PersonAttributeJsonVO);
        API_DEF_ADD_PATH_PARAMS(String, "xunique", ZH_WORDS_GETTER("Personattribute.query.summary") , 1 , true);
    }

    // 3.2 定义路径查询接口处理
    ENDPOINT(API_M_GET, "personal-management/query-person-attribute/{xunique}", queryPersonAttribute, PATH(String, xunique), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execQueryPersonAttribute(xunique));
    }


   //  3.1 定义新增接口描述
    ENDPOINT_INFO(addPersonAttribute) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Personattribute.add.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

    }

    // 3.2 定义新增接口处理
    ENDPOINT(API_M_POST, "personal-management/add-person-attribute", addPersonAttribute, BODY_DTO(PersonAttributeDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execAddPersonAttribute(dto));
    }


    // 3.1 定义修改接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Personattribute.modify.summary"), modifyPerson, Uint64JsonVO::Wrapper);

    // 3.2 定义修改接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "personal-management/modify-person-attribute/{xunique}", modifyPerson, BODY_DTO(PersonAttributeDTO::Wrapper, dto), execModifyPersonAttribute(dto));

    //// 3.1 定义删除接口描述
    ENDPOINT_INFO(removePersonAttribute) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Personattribute.delete.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
        API_DEF_ADD_PATH_PARAMS(String, "xunique", ZH_WORDS_GETTER("Personattribute.delete.summary"), 1, true);
    }

    //// 3.2 定义删除接口处理
    ENDPOINT(API_M_DEL, "personal-management/del-person-attribute", removePersonAttribute, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execRemovePersonAttribute(id));
    } 

private:
    // 执行获取个人属性 定义接口执行函数 
    PersonAttributeJsonVO::Wrapper execQueryPersonAttribute(const String& id);

    // 执行新增个人属性 定义接口执行函数
    StringJsonVO::Wrapper execAddPersonAttribute(const PersonAttributeDTO::Wrapper& dto);

    //// 执行修改个人属性 定义接口执行函数
    StringJsonVO::Wrapper execModifyPersonAttribute(const PersonAttributeDTO::Wrapper& dto);

    // 执行删除个人属性 定义接口执行函数
    StringJsonVO::Wrapper execRemovePersonAttribute(const String& id);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // PERSON_ATTRIBUTE_CONTROLLER_H