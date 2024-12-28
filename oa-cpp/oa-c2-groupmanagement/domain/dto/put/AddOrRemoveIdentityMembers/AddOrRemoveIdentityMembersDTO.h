#pragma once

#ifndef _AddOrRemoveIdentityMembers_DTO_
#define _AddOrRemoveIdentityMembers_DTO_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 传输对象
 */
class AddOrRemoveIdentityMembersDTO : public oatpp::DTO
{
	DTO_INIT(AddOrRemoveIdentityMembersDTO, DTO);
	// 唯一标识
	DTO_FIELD(String, groupxid);
	DTO_FIELD_INFO(groupxid) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id");
	}
	// 属于该组的身份成员
	DTO_FIELD(String, xidentityList);
	DTO_FIELD_INFO(xidentityList) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.xidentityList");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_AddOrRemoveIdentityMembers_DTO_