#pragma once
#ifndef _MEMBER_H_
#define _MEMBER_H_

#include "../../GlobalInclude.h"
#include "domain/dto/add_del_PersonMember/MemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MemberVO : public oatpp::DTO
{
	DTO_INIT(MemberVO, DTO);
	//Ա���ǳ�
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("add_del_PersonMember.field.name"),true,"john");
	//Ա������
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("add_del_PersonMember.field.id"), true, "1");
	//�ֻ�����
	API_DTO_FIELD(String, phone, ZH_WORDS_GETTER("add_del_PersonMember.field.phone"), true, "123456");
	//�����ʼ�
	API_DTO_FIELD(String, email, ZH_WORDS_GETTER("add_del_PersonMember.field.email"), true, "176@qq.com");
	
};
/**
 * Ա����Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MemberJsonVO : public JsonVO<MemberVO::Wrapper> {
	DTO_INIT(MemberJsonVO, JsonVO<MemberVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEMBER_H_