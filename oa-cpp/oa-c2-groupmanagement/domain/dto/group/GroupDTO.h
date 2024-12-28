#pragma once
#ifndef _GROUP_DTO_
#define _GROUP_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class GroupDTO : public oatpp::DTO
{
	DTO_INIT(GroupDTO, DTO);
	//编号
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("group.field.id"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("group。field.name"));
	//描述
	API_DTO_FIELD_DEFAULT(String, info, ZH_WORDS_GETTER("group.field.info"));
};

class UserDTO : public oatpp::DTO
{
	DTO_INIT(UserDTO, DTO);
	// 人员名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("role.field.name"));
	// 人员工号
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("role.field.id"));
	// 手机号码
	API_DTO_FIELD_DEFAULT(String, phone, ZH_WORDS_GETTER("role.field.phone"));
	// 邮件地址
	API_DTO_FIELD_DEFAULT(String, mail, ZH_WORDS_GETTER("role.field.mail"));
};

/**
 * 示例分页传输对象
 */
class UserPageDTO : public PageDTO<UserDTO::Wrapper>
{
	DTO_INIT(UserPageDTO, PageDTO<UserDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_DTO_