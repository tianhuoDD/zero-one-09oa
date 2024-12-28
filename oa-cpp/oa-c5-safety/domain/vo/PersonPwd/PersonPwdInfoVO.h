#pragma once
#ifndef _PERSONPWDINFOVO_H_
#define _PERSONPWDINFOVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/PersonPwd/PersonPwdInfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * //个人密码信息显示对象
 */
class PersonPwdInfoVO : public oatpp::DTO {

	DTO_INIT(PersonPwdInfoVO, DTO);
	//传递的数据:数据唯一标识id，密码password
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("safety.personpassword.field.id"), true, "abc123");
	API_DTO_FIELD(String, password, ZH_WORDS_GETTER("safety.personpassword.field.password"), true, "123456");

};

//个人密码信息显示JsonVO，用于相应给客户端的Json对象
class PersonPwdInfoJsonVO : public JsonVO<PersonPwdInfoDTO::Wrapper> {
	DTO_INIT(PersonPwdInfoJsonVO, JsonVO<PersonPwdInfoDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // _PERSONPWDINFOVO_H_