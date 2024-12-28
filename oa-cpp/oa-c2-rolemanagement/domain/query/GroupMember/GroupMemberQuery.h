#pragma once
#ifndef _GROUPMEMBER_QUERY_
#define _GROUPMEMBER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class GroupMemberQuery : public PageQuery
{
	DTO_INIT(GroupMemberQuery, PageQuery);
	//Ⱥ������
	DTO_FIELD(String, groupname);
	DTO_FIELD_INFO(groupname) {
		info->description = ZH_WORDS_GETTER("queryGroupMember.field.groupname");
	}
	// Ⱥ��ȫ��
	DTO_FIELD(String, groupnameA);
	DTO_FIELD_INFO(groupnameA) {
		info->description = ZH_WORDS_GETTER("queryGroupMember.field.groupnameA");
	}
	// Ⱥ������
	DTO_FIELD(String, groupdes);
	DTO_FIELD_INFO(groupdes) {
		info->description = ZH_WORDS_GETTER("queryGroupMember.field.groupdes");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUPMEMBER_QUERY_