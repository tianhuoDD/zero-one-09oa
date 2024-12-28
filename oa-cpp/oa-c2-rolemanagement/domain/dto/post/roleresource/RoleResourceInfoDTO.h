#pragma once

#ifndef _ROLERESOURCEINFODTO_H_
#define _ROLERESOURCEINFODTO_H_

#include "../../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO) 

class RoleResourceInfoDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(RoleResourceInfoDTO, DTO);
	//角色id
	API_DTO_FIELD(String, roleId, ZH_WORDS_GETTER("role.field.roleId"), true, "1323bc45");
	// 资源名称
	API_DTO_FIELD_DEFAULT(String, text, ZH_WORDS_GETTER("role.field.resourceName"));
	// 菜单描述
	API_DTO_FIELD_DEFAULT(UInt32, is_button, ZH_WORDS_GETTER("role.field.icon"));
	// 菜单类型
	API_DTO_FIELD_DEFAULT(UInt32, menu_type, ZH_WORDS_GETTER("role.field.href"));
	// 子菜单
	API_DTO_FIELD(List<RoleResourceInfoDTO::Wrapper>, children, ZH_WORDS_GETTER("role.field.childResource"), false, {});


public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<RoleResourceInfoDTO>(child), Wrapper::Class::getType()));
	}
};




#include OATPP_CODEGEN_END(DTO)

#endif // !_ROLERESOURCEINFODTO_H_
