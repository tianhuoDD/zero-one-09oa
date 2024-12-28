#include "stdafx.h"
#include "MenuAutorityController.h"
#include "../../../service/menu/useautority/MenuAutorityService.h"
#include "../../ApiDeclarativeServicesHelper.h"

MenuUseAutorityPageJsonVO::Wrapper MenuAutorityController::execQueryMenuUseAutority(const MenuUseAutorityQuery::Wrapper& query, const PayloadDTO& payload) {/*, const PayloadDTO& payload*/
	// 定义一个Service
	MenuAutorityService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MenuUseAutorityPageJsonVO::createShared();
	jvo->success(result);
	
	return jvo;
}