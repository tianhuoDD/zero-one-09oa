#pragma once
#ifndef _GROUP_VO_
#define _GROUP_VO_

#include "../../GlobalInclude.h"
#include "../../dto/group/GroupDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//class GroupVO : public oatpp::DTO
//{
//	DTO_INIT(GroupVO, DTO);
//	// 编号
//	// //数据唯一标识
//	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("group.field.id"), true, "007");
//	//描述
//	API_DTO_FIELD(String, info, ZH_WORDS_GETTER("group.field.info"), true, "111");
//	//姓名
//	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("group。field.name"), true, "111");
//	
//};
//
//class UserVO : public oatpp::DTO
//{
//	DTO_INIT(UserVO, DTO);
//	// 人员名称
//	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("role.field.name"),false,"567");
//	// 人员工号
//	API_DTO_FIELD_DEFAULT(Int32, id, ZH_WORDS_GETTER("role.field.id"),false,1);
//	// 手机号码
//	API_DTO_FIELD_DEFAULT(String, phone, ZH_WORDS_GETTER("role.field.phone"),false,"18584168650");
//	// 邮件地址
//	API_DTO_FIELD_DEFAULT(String, mail, ZH_WORDS_GETTER("role.field.mail"),false,"01xq@qq.com");
//};

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class UserJsonVO : public JsonVO<UserDTO::Wrapper> {
	DTO_INIT(UserJsonVO, JsonVO<UserDTO::Wrapper>);
};
/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class UserPageJsonVO : public JsonVO<UserPageDTO::Wrapper> {
	DTO_INIT(UserPageJsonVO, JsonVO<UserPageDTO::Wrapper>);
};
/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */

class GroupJsonVO : public JsonVO<GroupDTO::Wrapper> {
	DTO_INIT(GroupJsonVO, JsonVO<GroupDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_GROUP_VO_