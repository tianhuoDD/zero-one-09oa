#pragma once
#ifndef _USERQUERY_H_
#define _USERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class UserQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(UserQuery, PageQuery);

	//名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("role.field.name");
	}
	// 编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("role.field.id");
	}
	// 手机号码
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("role.field.phone");
	}
	// 邮件
	DTO_FIELD(String, mail);
	DTO_FIELD_INFO(mail) {
		info->description = ZH_WORDS_GETTER("role.field.mail");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_