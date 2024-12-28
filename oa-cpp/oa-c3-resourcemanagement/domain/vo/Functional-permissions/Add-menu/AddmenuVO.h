#pragma once
#ifndef _ADDMENU_VO_
#define _ADDMENU_VO_
#include "../../../GlobalInclude.h"
#include "../../../dto/Functional-permissions/Add-menu/AddmenuDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class AddmenuVO :public oatpp::DTO
{
	DTO_INIT(AddmenuVO, DTO);
	// 编号 工号 也是数据唯一标识
	DTO_FIELD(String, role_id);
	DTO_FIELD_INFO(role_id) {
		info->description = ZH_WORDS_GETTER("Functional-permissions.Add-menu.field.id");
	}
	
	DTO_FIELD(String, permissions);
	//权限
	DTO_FIELD_INFO(permissions) {
		info->description = ZH_WORDS_GETTER("Functional-permissions.Add-menu.field.permissions");
	}
};
class AddmenuJsonVO : public JsonVO<AddmenuVO::Wrapper> {
	DTO_INIT(AddmenuJsonVO, JsonVO<AddmenuVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_