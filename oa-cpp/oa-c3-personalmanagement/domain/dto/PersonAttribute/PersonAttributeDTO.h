#pragma once
#ifndef PERSONATTRIBUTEDTO_H
#define PERSONATTRIBUTEDTO_H

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
//#include "../lib-oatpp/include/oatpp/codegen/api_controller/base_define.hpp"
// Oat++ 代码生成开始
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个人的信息数据传输模型
 */
class PersonAttributeDTO : public oatpp::DTO {
    DTO_INIT(PersonAttributeDTO, DTO);
    // 标识
    API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("person-attribute.field.id"));
    // 创建时间
    API_DTO_FIELD_DEFAULT(String, xcreateTime, ZH_WORDS_GETTER("person-attribute.field.createTime"));
    // 序列号
    API_DTO_FIELD_DEFAULT(String, xsequence, ZH_WORDS_GETTER("person-attribute.field.sequence"));
    // 更新时间
    API_DTO_FIELD_DEFAULT(String, xupdateTime, ZH_WORDS_GETTER("person-attribute.field.updateTime"));

    // 分配因子
    API_DTO_FIELD_DEFAULT(Int32, xdistributeFactor, ZH_WORDS_GETTER("person-attribute.field.distributeFactor"));
    // 描述
    API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("person-attribute.field.description"));
    // 区分名
    API_DTO_FIELD_DEFAULT(String, xdistinguishedName, ZH_WORDS_GETTER("person-attribute.field.distinguishedName"));

    // 名称
    API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("person-attribute.field.name"));

    // 排序号
    API_DTO_FIELD_DEFAULT(Int32, xorderNumber, ZH_WORDS_GETTER("person-attribute.field.orderNumber"));

    // 人员
    API_DTO_FIELD_DEFAULT(String, xperson, ZH_WORDS_GETTER("person-attribute.field.person"));

    // 拼音
    API_DTO_FIELD_DEFAULT(String, xpinyin, ZH_WORDS_GETTER("person-attribute.field.pinyin"));

    // 拼音首字母
    API_DTO_FIELD_DEFAULT(String, xpinyinInitial, ZH_WORDS_GETTER("person-attribute.field.pinyinInitial"));
    // 唯一标识
    API_DTO_FIELD_DEFAULT(String, xunique, ZH_WORDS_GETTER("person-attribute.field.unique"));

};



#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_