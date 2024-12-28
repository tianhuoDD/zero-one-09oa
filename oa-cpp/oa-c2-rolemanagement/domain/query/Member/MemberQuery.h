#pragma once
#ifndef _MEMBER_QUERY_
#define _MEMBER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class MemberQuery : public PageQuery
{
	DTO_INIT(MemberQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("add_del_PersonMember.field.name");
	}
	// 工号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("add_del_PersonMember.field.id");
	}
	//手机号码
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("add_del_PersonMember.field.phone");
	}
	// 电子邮件
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("add_del_PersonMember.field.email");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONINFO_QUERY_
