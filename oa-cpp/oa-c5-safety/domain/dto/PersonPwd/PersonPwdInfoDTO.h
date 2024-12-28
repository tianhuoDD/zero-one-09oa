#pragma once
#ifndef _PERSONPWDINFODTO_H_
#define _PERSONPWDINFODTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class PersonPwdInfoDTO : public oatpp::DTO
{
	DTO_INIT(PersonPwdInfoDTO, DTO);

	//数据记录id和密码password
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("safety.personpassword.field.id"), true, "abc123");
	API_DTO_FIELD(String, password, ZH_WORDS_GETTER("safety.personpassword.field.password"), true, "123456");


};


#include OATPP_CODEGEN_END(DTO)
#endif // _PERSONPWDINFODTO_H_