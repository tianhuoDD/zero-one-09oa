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
    // �´����û��ĳ�ʼ����
    API_DTO_FIELD_DEFAULT(String, init_password_description, ZH_WORDS_GETTER("sys.setting.field.init_password_description"));
    // �û���ʼ����
    API_DTO_FIELD_DEFAULT(String, init_password_value, ZH_WORDS_GETTER("sys.setting.field.init_password_value"));
    // ���������������
    API_DTO_FIELD_DEFAULT(String, expiry_days_description, ZH_WORDS_GETTER("sys.setting.field.password_expiry_days_description"));
    // �༭�����������
    API_DTO_FIELD_DEFAULT(Int32, expiry_days, ZH_WORDS_GETTER("sys.setting.field.edit_password_expiry_days"));
    // ���븴�Ӷ�����
    API_DTO_FIELD_DEFAULT(String, complexity_description, ZH_WORDS_GETTER("sys.setting.field.password_complexity"));
    // ���볤����Сֵ
    API_DTO_FIELD_DEFAULT(Int32, min_length, ZH_WORDS_GETTER("sys.setting.field.password_min_length"));
    // ���볤�����ֵ
    API_DTO_FIELD_DEFAULT(Int32, max_length, ZH_WORDS_GETTER("sys.setting.field.password_max_length"));
    // ������� - Сд��ĸ
    API_DTO_FIELD_DEFAULT(String, rule_lowercase, ZH_WORDS_GETTER("sys.setting.field.password_rule_lowercase"));
    // ������� - ����
    API_DTO_FIELD_DEFAULT(String, rule_number, ZH_WORDS_GETTER("sys.setting.field.password_rule_number"));
    // ������� - ��д��ĸ
    API_DTO_FIELD_DEFAULT(String, rule_uppercase, ZH_WORDS_GETTER("sys.setting.field.password_rule_uppercase"));
    // ������� - �����ַ�
    API_DTO_FIELD_DEFAULT(String, rule_special_character, ZH_WORDS_GETTER("sys.setting.field.password_rule_special_character"));
    // �Ƿ�����
    API_DTO_FIELD_DEFAULT(Boolean, rule_enabled, ZH_WORDS_GETTER("sys.setting.field.password_rule_enabled"));
    // ������ܴ�������
    API_DTO_FIELD_DEFAULT(String, encryption_description, ZH_WORDS_GETTER("sys.setting.field.password_encryption_description"));
    // ������ܴ��俪��״̬
    API_DTO_FIELD_DEFAULT(String, encryption_status, ZH_WORDS_GETTER("sys.setting.field.password_encryption_status"));
    // ����ǿ���޸�����
    API_DTO_FIELD_DEFAULT(String, force_change_description, ZH_WORDS_GETTER("sys.setting.field.password_force_change_description"));
    // ����ǿ���޸Ŀ���״̬
    API_DTO_FIELD_DEFAULT(String, force_change_status, ZH_WORDS_GETTER("sys.setting.field.password_force_change_status"));
};

#include OATPP_CODEGEN_END(DTO)

#endif
