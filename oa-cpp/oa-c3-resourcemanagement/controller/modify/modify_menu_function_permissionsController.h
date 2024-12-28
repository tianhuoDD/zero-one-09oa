#pragma once
#ifndef _MODIFY_MENU_FUNCTION_PERMISSIONSCONTROLLER_
#define _MODIFY_MENU_FUNCTION_PERMISSIONSCONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/modify/modify_menulist_fpDTO.h"

#include "../../domain/vo/modify/modify_menulist_fpVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class modify_menu_function_permissionsController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(modify_menu_function_permissionsController);

public:
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sample.put.summary"), modifymenupermissions, StringJsonVO::Wrapper);
	
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "resource-management/modify-menulist-function-permissions", modifymenupermissions, BODY_DTO(modify_menulist_fpDTO::Wrapper, dto), execModifymenupermissions(dto));

private:
	StringJsonVO::Wrapper execModifymenupermissions(const modify_menulist_fpDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_MODIFY_MENU_FUNCTION_PERMISSIONSCONTROLLER_
