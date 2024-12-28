#pragma once

#ifndef _ROLERESOURCELISTDTO_H_
#define _ROLERESOURCELISTDTO_H_

#include "../../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO) 

class RoleResourceListDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(RoleResourceListDTO, DTO);
	//²Ëµ¥idList
	API_DTO_FIELD(List<String>, idList, ZH_WORDS_GETTER("role.field.menuList"), true, {});
	//½ÇÉ«Î¨Ò»id
	API_DTO_FIELD(String, roleId, ZH_WORDS_GETTER("role.field.roleId"), true, "133bce45");

};




#include OATPP_CODEGEN_END(DTO)

#endif // !_ROLERESOURCELISTDTO_H_
