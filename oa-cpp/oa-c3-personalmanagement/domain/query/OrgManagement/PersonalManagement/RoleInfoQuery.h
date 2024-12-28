#pragma once
#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class RoleInfoQuery : public PageQuery
{
	DTO_INIT(RoleInfoQuery, PageQuery);
	// ְ��Ψһ��ʶ
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.RoleInfo.Xid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // _ROLEINFOQUERY_H_