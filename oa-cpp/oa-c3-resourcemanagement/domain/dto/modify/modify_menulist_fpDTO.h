#pragma once
#ifndef _MODIFY_MENULIST_FPDTO_
#define _MODIFY_MENULIST_FPDTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class modify_menulist_fpDTO : public oatpp::DTO
{
	DTO_INIT(modify_menulist_fpDTO, DTO);
	// 唯一编号
	DTO_FIELD(String, role_id);
	DTO_FIELD_INFO(role_id) {
		info->description = ZH_WORDS_GETTER("sample.field.role_id");
	}
	// 身份名称
	DTO_FIELD(String, menuList);
	DTO_FIELD_INFO(menuList) {
		info->description = ZH_WORDS_GETTER("sample.field.menuList");
	}
	// 主身份
	DTO_FIELD(Int32, xorderColumn);
	DTO_FIELD_INFO(xorderColumn) {
		info->description = ZH_WORDS_GETTER("sample.field.xorderColumn");
	}
};

class modifymenulistPageDTO : public PageDTO<modify_menulist_fpDTO::Wrapper>
{
	DTO_INIT(modifymenulistPageDTO, PageDTO<modify_menulist_fpDTO::Wrapper>);
};




#endif // !_MODIFY_MENULIST_FPDTO_
