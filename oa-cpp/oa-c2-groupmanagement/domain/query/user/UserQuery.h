#pragma once
#ifndef _USERQUERY_H_
#define _USERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class UserQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(UserQuery, PageQuery);

	//����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("role.field.name");
	}
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("role.field.id");
	}
	// �ֻ�����
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("role.field.phone");
	}
	// �ʼ�
	DTO_FIELD(String, mail);
	DTO_FIELD_INFO(mail) {
		info->description = ZH_WORDS_GETTER("role.field.mail");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_