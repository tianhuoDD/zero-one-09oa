#pragma once
#ifndef PERSONATTRIBUTEQUERY_H_
#define PERSONATTRIBUTEQUERY_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)
#include "domain/vo/JsonVO.h"

/**
 * 通过个人id获取人员信息
 */
class PersonalAttributeQuery : public oatpp::DTO
{
    DTO_INIT(PersonalAttributeQuery, DTO)

    // 个人id
    DTO_FIELD(oatpp::String, id);
    DTO_FIELD_INFO(id) {
        info->description =
           // "Query attribute by `xunique`";
        ZH_WORDS_GETTER("Personattribute.query.xunique");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif