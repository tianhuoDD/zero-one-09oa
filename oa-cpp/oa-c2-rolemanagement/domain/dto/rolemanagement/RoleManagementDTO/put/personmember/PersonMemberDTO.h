#pragma once
#pragma once
#ifndef PERSONMEMBERDTO_H_
#define PERSONMEMBERDTO_H_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PersonMemberDTO : public oatpp::DTO
{
	DTO_INIT(PersonMemberDTO, DTO);
	//员工工号
	API_DTO_FIELD(List<String>, xpersonList, ZH_WORDS_GETTER("PersonMember.field.xpersonList"), true, {});
	API_DTO_FIELD_DEFAULT(String,role_xid , ZH_WORDS_GETTER("PersonMember.field.ROLE_XID"));
	//API_DTO_FIELD_DEFAULT(UInt64, xorderColumn, ZH_WORDS_GETTER("PersonMember.field.xorderColumn"));
};

/**
 * 分页传输对象
 */
class PersonMemberPageDTO : public PageDTO<PersonMemberDTO::Wrapper>
{
	DTO_INIT(PersonMemberPageDTO, PageDTO<PersonMemberDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !PERSONMEMBERDTO_H_