#pragma once
#pragma once
#ifndef PERSONMEMBERDTO_H_
#define PERSONMEMBERDTO_H_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class PersonMemberDTO : public oatpp::DTO
{
	DTO_INIT(PersonMemberDTO, DTO);
	//Ա������
	API_DTO_FIELD(List<String>, xpersonList, ZH_WORDS_GETTER("PersonMember.field.xpersonList"), true, {});
	API_DTO_FIELD_DEFAULT(String,role_xid , ZH_WORDS_GETTER("PersonMember.field.ROLE_XID"));
	//API_DTO_FIELD_DEFAULT(UInt64, xorderColumn, ZH_WORDS_GETTER("PersonMember.field.xorderColumn"));
};

/**
 * ��ҳ�������
 */
class PersonMemberPageDTO : public PageDTO<PersonMemberDTO::Wrapper>
{
	DTO_INIT(PersonMemberPageDTO, PageDTO<PersonMemberDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !PERSONMEMBERDTO_H_