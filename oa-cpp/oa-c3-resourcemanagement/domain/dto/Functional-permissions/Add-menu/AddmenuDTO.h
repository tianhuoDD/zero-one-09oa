#pragma once
#ifndef _ADDMENUDTO_H_
#define _ADDMENUDTO_H_
#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class AddmenuDTO:public oatpp::DTO
{
	DTO_INIT(AddmenuDTO, DTO);
	// 编号 工号 也是数据唯一标识
	// string
	DTO_FIELD(String, role_id);
	DTO_FIELD_INFO(role_id) {
		info->description = ZH_WORDS_GETTER("Functional-permissions.Add-menu.field.id");
	}
	DTO_FIELD(String, permissions);
	DTO_FIELD_INFO(permissions) {
		info->description = ZH_WORDS_GETTER("Functional-permissions.Add-menu.field.permissions");
	}
	//API_DTO_FIELD_DEFAULT(String, permissions, ZH_WORDS_GETTER("Functional-permissions.Add-menu.field.permissions"));
};
class AddmenuPageDTO : public PageDTO<AddmenuDTO::Wrapper>
{
	DTO_INIT(AddmenuPageDTO, PageDTO<AddmenuDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif