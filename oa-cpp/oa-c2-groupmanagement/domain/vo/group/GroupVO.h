#pragma once
#ifndef _GROUP_VO_
#define _GROUP_VO_

#include "../../GlobalInclude.h"
#include "../../dto/group/GroupDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//class GroupVO : public oatpp::DTO
//{
//	DTO_INIT(GroupVO, DTO);
//	// ���
//	// //����Ψһ��ʶ
//	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("group.field.id"), true, "007");
//	//����
//	API_DTO_FIELD(String, info, ZH_WORDS_GETTER("group.field.info"), true, "111");
//	//����
//	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("group��field.name"), true, "111");
//	
//};
//
//class UserVO : public oatpp::DTO
//{
//	DTO_INIT(UserVO, DTO);
//	// ��Ա����
//	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("role.field.name"),false,"567");
//	// ��Ա����
//	API_DTO_FIELD_DEFAULT(Int32, id, ZH_WORDS_GETTER("role.field.id"),false,1);
//	// �ֻ�����
//	API_DTO_FIELD_DEFAULT(String, phone, ZH_WORDS_GETTER("role.field.phone"),false,"18584168650");
//	// �ʼ���ַ
//	API_DTO_FIELD_DEFAULT(String, mail, ZH_WORDS_GETTER("role.field.mail"),false,"01xq@qq.com");
//};

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UserJsonVO : public JsonVO<UserDTO::Wrapper> {
	DTO_INIT(UserJsonVO, JsonVO<UserDTO::Wrapper>);
};
/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UserPageJsonVO : public JsonVO<UserPageDTO::Wrapper> {
	DTO_INIT(UserPageJsonVO, JsonVO<UserPageDTO::Wrapper>);
};
/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */

class GroupJsonVO : public JsonVO<GroupDTO::Wrapper> {
	DTO_INIT(GroupJsonVO, JsonVO<GroupDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_GROUP_VO_