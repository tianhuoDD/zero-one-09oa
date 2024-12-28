#pragma once
#ifndef _MEMBER_H_
#define _MEMBER_H_

#include "../../GlobalInclude.h"
#include "domain/dto/add_del_PersonMember/MemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class MemberVO : public oatpp::DTO
{
	DTO_INIT(MemberVO, DTO);
	//员工昵称
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("add_del_PersonMember.field.name"),true,"john");
	//员工工号
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("add_del_PersonMember.field.id"), true, "1");
	//手机号码
	API_DTO_FIELD(String, phone, ZH_WORDS_GETTER("add_del_PersonMember.field.phone"), true, "123456");
	//电子邮件
	API_DTO_FIELD(String, email, ZH_WORDS_GETTER("add_del_PersonMember.field.email"), true, "176@qq.com");
	
};
/**
 * 员工信息显示JsonVO，用于响应给客户端的Json对象
 */
class MemberJsonVO : public JsonVO<MemberVO::Wrapper> {
	DTO_INIT(MemberJsonVO, JsonVO<MemberVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEMBER_H_