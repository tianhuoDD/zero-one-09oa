#pragma once
#ifndef _GROUP_DTO_
#define _GROUP_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class GroupDTO : public oatpp::DTO
{
	DTO_INIT(GroupDTO, DTO);
	//���
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("group.field.id"));
	//����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("group��field.name"));
	//����
	API_DTO_FIELD_DEFAULT(String, info, ZH_WORDS_GETTER("group.field.info"));
};

class UserDTO : public oatpp::DTO
{
	DTO_INIT(UserDTO, DTO);
	// ��Ա����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("role.field.name"));
	// ��Ա����
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("role.field.id"));
	// �ֻ�����
	API_DTO_FIELD_DEFAULT(String, phone, ZH_WORDS_GETTER("role.field.phone"));
	// �ʼ���ַ
	API_DTO_FIELD_DEFAULT(String, mail, ZH_WORDS_GETTER("role.field.mail"));
};

/**
 * ʾ����ҳ�������
 */
class UserPageDTO : public PageDTO<UserDTO::Wrapper>
{
	DTO_INIT(UserPageDTO, PageDTO<UserDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_DTO_