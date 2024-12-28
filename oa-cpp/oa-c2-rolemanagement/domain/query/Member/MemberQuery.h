#pragma once
#ifndef _MEMBER_QUERY_
#define _MEMBER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class MemberQuery : public PageQuery
{
	DTO_INIT(MemberQuery, PageQuery);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("add_del_PersonMember.field.name");
	}
	// ����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("add_del_PersonMember.field.id");
	}
	//�ֻ�����
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("add_del_PersonMember.field.phone");
	}
	// �����ʼ�
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("add_del_PersonMember.field.email");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONINFO_QUERY_
