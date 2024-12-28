#pragma once
#ifndef _MODIFY_MENU_FPVO_
#define _MODIFY_MENU_FPVO_

#include "../../GlobalInclude.h"
#include "../../dto/modify/modify_menulist_fpDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class modifiy_menu_fpJsonVO : public JsonVO<modify_menulist_fpDTO::Wrapper> {
	DTO_INIT(modifiy_menu_fpJsonVO, JsonVO<modify_menulist_fpDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MODIFY_MENU_FPVO_