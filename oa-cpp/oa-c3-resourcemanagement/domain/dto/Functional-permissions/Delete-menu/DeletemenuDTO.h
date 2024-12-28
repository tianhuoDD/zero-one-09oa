#pragma once
#ifndef _DeleteINFO_H_
#define _DeleteINFO_H_
#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class DeletemenuDTO :public oatpp::DTO
{
	DTO_INIT(DeletemenuDTO, DTO);
	DTO_FIELD(String, role_id);
	DTO_FIELD_INFO(role_id) {
		info->description = ZH_WORDS_GETTER("Functional-permissions.Add-menu.field.id");
	}
	//DTO_FIELD(String, permissions);
	//х╗оч
	DTO_FIELD(oatpp::List<String>, permissions);
	DTO_FIELD_INFO(permissions) {
		info->description = ZH_WORDS_GETTER("Functional-permissions.Add-menu.field.permissions");
	}


};
#include  OATPP_CODEGEN_END(DTO)

#endif