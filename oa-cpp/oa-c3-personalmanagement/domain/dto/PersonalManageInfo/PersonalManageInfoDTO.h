#pragma once
#ifndef PERSONALMANAGEINFODTO
#define PERSONALMANAGEINFODTO
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PersonalManageInfoDTO : public oatpp::DTO {
	DTO_INIT(PersonalManageInfoDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, xunique, ZH_WORDS_GETTER("personmanageinfo.field.xunique"));
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("personmanageinfo.field.xname"));
	API_DTO_FIELD_DEFAULT(String, xmobile, ZH_WORDS_GETTER("personmanageinfo.field.xmobile"));
	API_DTO_FIELD_DEFAULT(String, xofficePhone, ZH_WORDS_GETTER("personmanageinfo.field.xofficePhone"));
	API_DTO_FIELD_DEFAULT(String, xgenderType, ZH_WORDS_GETTER("personmanageinfo.field.xgenderType"));
	API_DTO_FIELD_DEFAULT(String, xmail, ZH_WORDS_GETTER("personmanageinfo.field.xmail"));
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
};

#include OATPP_CODEGEN_END(DTO)
#endif // !PERSONALMANAGEINFODTO
