#pragma once

#ifndef _GetOrganizationMembers_VO_
#define _GetOrganizationMembers_VO_

#include "../../../GlobalInclude.h"
#include "../../../query/get/GetOrganizationMembers/GetOrganizationMembersQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//
//class GetOrganizationMembersVO : public oatpp::DTO
//{
//	DTO_INIT(GetOrganizationMembersVO, DTO);
//	// Ψһ��ʶ
//	DTO_FIELD(String, id);
//	DTO_FIELD_INFO(id) {
//		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id");
//	}
//	// ����
//	DTO_FIELD(String, name);
//	DTO_FIELD_INFO(name) {
//		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.name");
//	}
//	// �㼶����
//	DTO_FIELD(String, groupname);
//	DTO_FIELD_INFO(groupname) {
//		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.groupname");
//	}
//};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetOrganizationMembersPageJsonVO : public JsonVO<GetOrganizationMembersQuery::Wrapper> {
	DTO_INIT(GetOrganizationMembersPageJsonVO, JsonVO<GetOrganizationMembersQuery::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GetOrganizationMembers_VO_