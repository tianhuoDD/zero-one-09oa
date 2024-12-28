#include "stdafx.h"
#include "MenuAutorityController.h"
#include "../../../service/menu/useautority/MenuAutorityService.h"
#include "../../ApiDeclarativeServicesHelper.h"

MenuUseAutorityPageJsonVO::Wrapper MenuAutorityController::execQueryMenuUseAutority(const MenuUseAutorityQuery::Wrapper& query, const PayloadDTO& payload) {/*, const PayloadDTO& payload*/
	// ����һ��Service
	MenuAutorityService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MenuUseAutorityPageJsonVO::createShared();
	jvo->success(result);
	
	return jvo;
}