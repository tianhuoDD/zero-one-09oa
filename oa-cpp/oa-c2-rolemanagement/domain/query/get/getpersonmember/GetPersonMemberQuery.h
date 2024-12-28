#pragma once
#ifndef _GETPERSONMEMBER_QUERY_
#define _GETPERSONMEMBER_QUERY_

#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class GetPersonMemberQuery : public PageQuery
{
	DTO_INIT(GetPersonMemberQuery, PageQuery);
	// ��Աid
	DTO_FIELD(String, ROLE_XID);
	DTO_FIELD_INFO(ROLE_XID) {
		info->description = ZH_WORDS_GETTER("PersonMember.field.ROLE_XID");
	}
	//// Ⱥ��id
	//DTO_FIELD(String, xgroupList);
	//DTO_FIELD_INFO(xgroupList) {
	//	info->description = ZH_WORDS_GETTER("PersonMember.field.xgroupList");
	//}
	//// ˳��
	//DTO_FIELD(UInt64, xorderColumn);
	//DTO_FIELD_INFO(xorderColumn) {
	//	info->description = ZH_WORDS_GETTER("PersonMember.field.xorderColumn");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETPERSONMEMBER_QUERY_