#pragma once

#ifndef _DELETEMENU_VO_
#define _DELETEMENU_VO_
#include "../../../GlobalInclude.h"

#include "../../../dto/Functional-permissions/Delete-menu/DeletemenuDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class DeletemenuVO :public oatpp::DTO
{
	DTO_INIT(DeletemenuVO, DTO);
	// 编号 工号 也是数据唯一标识
	DTO_FIELD(String, role_id);
	DTO_FIELD_INFO(role_id) {
		info->description = ZH_WORDS_GETTER("Functional-permissions.Add-menu.field.id");
	}
	
	DTO_FIELD(oatpp::List<String>, permissions);
	//权限
	DTO_FIELD_INFO(permissions) {
		info->description = ZH_WORDS_GETTER("Functional-permissions.Add-menu.field.permissions");
	}
};
class DeletemenuJsonVO : public JsonVO<DeletemenuVO::Wrapper> {
	DTO_INIT(DeletemenuJsonVO, JsonVO<DeletemenuVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SA