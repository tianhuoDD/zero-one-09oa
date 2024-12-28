#pragma once

#ifndef _USERPASSWORD_DTO_
#define _USERPASSWORD_DTO_

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UserPasswordDTO : public oatpp::DTO
{
    DTO_INIT(UserPasswordDTO, DTO);
    // 新创建用户的初始密码
    API_DTO_FIELD_DEFAULT(String, init_password_description, ZH_WORDS_GETTER("sys.setting.field.init_password_description"));
    // 用户初始密码
    API_DTO_FIELD_DEFAULT(String, init_password_value, ZH_WORDS_GETTER("sys.setting.field.init_password_value"));
    // 密码过期天数描述
    API_DTO_FIELD_DEFAULT(String, expiry_days_description, ZH_WORDS_GETTER("sys.setting.field.password_expiry_days_description"));
    // 编辑密码过期天数
    API_DTO_FIELD_DEFAULT(Int32, expiry_days, ZH_WORDS_GETTER("sys.setting.field.edit_password_expiry_days"));
    // 密码复杂度设置
    API_DTO_FIELD_DEFAULT(String, complexity_description, ZH_WORDS_GETTER("sys.setting.field.password_complexity"));
    // 密码长度最小值
    API_DTO_FIELD_DEFAULT(Int32, min_length, ZH_WORDS_GETTER("sys.setting.field.password_min_length"));
    // 密码长度最大值
    API_DTO_FIELD_DEFAULT(Int32, max_length, ZH_WORDS_GETTER("sys.setting.field.password_max_length"));
    // 密码规则 - 小写字母
    API_DTO_FIELD_DEFAULT(String, rule_lowercase, ZH_WORDS_GETTER("sys.setting.field.password_rule_lowercase"));
    // 密码规则 - 数字
    API_DTO_FIELD_DEFAULT(String, rule_number, ZH_WORDS_GETTER("sys.setting.field.password_rule_number"));
    // 密码规则 - 大写字母
    API_DTO_FIELD_DEFAULT(String, rule_uppercase, ZH_WORDS_GETTER("sys.setting.field.password_rule_uppercase"));
    // 密码规则 - 特殊字符
    API_DTO_FIELD_DEFAULT(String, rule_special_character, ZH_WORDS_GETTER("sys.setting.field.password_rule_special_character"));
    // 是否启用
    API_DTO_FIELD_DEFAULT(Boolean, rule_enabled, ZH_WORDS_GETTER("sys.setting.field.password_rule_enabled"));
    // 密码加密传输描述
    API_DTO_FIELD_DEFAULT(String, encryption_description, ZH_WORDS_GETTER("sys.setting.field.password_encryption_description"));
    // 密码加密传输开关状态
    API_DTO_FIELD_DEFAULT(String, encryption_status, ZH_WORDS_GETTER("sys.setting.field.password_encryption_status"));
    // 密码强制修改描述
    API_DTO_FIELD_DEFAULT(String, force_change_description, ZH_WORDS_GETTER("sys.setting.field.password_force_change_description"));
    // 密码强制修改开关状态
    API_DTO_FIELD_DEFAULT(String, force_change_status, ZH_WORDS_GETTER("sys.setting.field.password_force_change_status"));
};

#include OATPP_CODEGEN_END(DTO)

#endif
