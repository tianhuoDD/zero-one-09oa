#pragma once

#ifndef _AddOrRemoveIdentityMembers_DTO_
#define _AddOrRemoveIdentityMembers_DTO_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������
 */
class AddOrRemoveIdentityMembersDTO : public oatpp::DTO
{
	DTO_INIT(AddOrRemoveIdentityMembersDTO, DTO);
	// Ψһ��ʶ
	DTO_FIELD(String, groupxid);
	DTO_FIELD_INFO(groupxid) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id");
	}
	// ���ڸ������ݳ�Ա
	DTO_FIELD(String, xidentityList);
	DTO_FIELD_INFO(xidentityList) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.xidentityList");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_AddOrRemoveIdentityMembers_DTO_