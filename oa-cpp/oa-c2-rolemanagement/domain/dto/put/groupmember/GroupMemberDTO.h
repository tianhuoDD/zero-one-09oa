#pragma once
#ifndef _GROUPMENBERDTO_H_
#define _GROUPMENBERDTO_H_

#include "../../../../domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GroupMemberDTO :public oatpp::DTO
{
	DTO_INIT(GroupMemberDTO, DTO);
	//群组成员唯一编码
	API_DTO_FIELD(List<String>, idList, ZH_WORDS_GETTER("role.field.idList"),true,{});
	//角色唯一id
	API_DTO_FIELD(String, roleId, ZH_WORDS_GETTER("role.field.roleId"), true, "13313bc4");

};

#include OATPP_CODEGEN_END(DTO)


#endif // !_GROUPMENBERDTO_H_
