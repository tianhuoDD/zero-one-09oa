#pragma once
#ifndef PERSONALMANAGEINFOVO
#define PERSONALMANAGEINFOVO
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PersonalManageInfoVO : public oatpp::DTO {
	DTO_INIT(PersonalManageInfoVO, DTO);
	API_DTO_FIELD(String, xunique, ZH_WORDS_GETTER("personmanageinfo.field.xunique"), true, "001");
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("personmanageinfo.field.xname"), true, "xiao ming");
	API_DTO_FIELD(String, xmobile, ZH_WORDS_GETTER("personmanageinfo.field.xmobile"), true, "138XXXXXXXX");
	API_DTO_FIELD_DEFAULT(String, xofficePhone, ZH_WORDS_GETTER("personmanageinfo.field.xofficePhone"));
	API_DTO_FIELD(String, xgenderType, ZH_WORDS_GETTER("personmanageinfo.field.xgenderType"), true, "m");
	API_DTO_FIELD_DEFAULT(String, xemail, ZH_WORDS_GETTER("personmanageinfo.field.xmail"));
	API_DTO_FIELD_DEFAULT(String, xqq, ZH_WORDS_GETTER("personmanageinfo.field.xqq"));
	API_DTO_FIELD_DEFAULT(String, xweixin, ZH_WORDS_GETTER("personmanageinfo.field.xweixin"));
	API_DTO_FIELD_DEFAULT(String, xboardDate, ZH_WORDS_GETTER("personmanageinfo.field.xboardDate"));
	API_DTO_FIELD_DEFAULT(String, xipAddress, ZH_WORDS_GETTER("personmanageinfo.field.xipAddress"));
	API_DTO_FIELD_DEFAULT(UInt64, xsubjectSecurityClearance, ZH_WORDS_GETTER("personmanageinfo.field.xsubjectSecurityClearance"));
	API_DTO_FIELD_DEFAULT(String, xemployee, ZH_WORDS_GETTER("personmanageinfo.field.xemployee"));
	API_DTO_FIELD_DEFAULT(String, xbirthday, ZH_WORDS_GETTER("personmanageinfo.field.xbirthday"));
	API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("personmanageinfo.field.xdescription"));
	API_DTO_FIELD_DEFAULT(String, xstatus, ZH_WORDS_GETTER("personmanageinfo.field.xstatus"));
	API_DTO_FIELD_DEFAULT(String, xsuperior, ZH_WORDS_GETTER("personmanageinfo.field.xsuperior"));
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("personmanageinfo.field.xid"));
};//我看示例版本的时候那里面都是空的，所以没有设置默认值

class PersonalManageInfoJsonVO : public JsonVO<PersonalManageInfoDTO::Wrapper> {
	DTO_INIT(PersonalManageInfoJsonVO, JsonVO<PersonalManageInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif