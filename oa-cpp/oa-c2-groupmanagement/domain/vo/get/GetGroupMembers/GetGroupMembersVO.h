#pragma once

#ifndef _GetGroupMembers_VO_
#define _GetGroupMembers_VO_

#include "../../../GlobalInclude.h"
#include "../../../query/get/GetGroupMembers/GetGroupMembersQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//class GetGroupMembersVO : public oatpp::DTO
//{
//	DTO_INIT(GetGroupMembersVO, DTO);
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
//	// Ⱥ��ȫ��
//	DTO_FIELD(String, allname);
//	DTO_FIELD_INFO(allname) {
//		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.allname");
//	}
//};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetGroupMembersPageJsonVO : public JsonVO<GetGroupMembersQuery::Wrapper> {
	DTO_INIT(GetGroupMembersPageJsonVO, JsonVO<GetGroupMembersQuery::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GetGroupMembers_VO_