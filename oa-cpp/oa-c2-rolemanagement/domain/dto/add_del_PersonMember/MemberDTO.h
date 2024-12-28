#pragma once
#ifndef MEMBERDTO_H_
#define MEMBERDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class MemberDTO : public oatpp::DTO
{
	DTO_INIT(MemberDTO, DTO);
	//Ա������
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("add_del_PersonMember.field.id"));
};

/**
 * ��ҳ�������
 */
class MemberPageDTO : public PageDTO<MemberDTO::Wrapper>
{
	DTO_INIT(MemberPageDTO, PageDTO<MemberDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !MEMBERDTO_H_