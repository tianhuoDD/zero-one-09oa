#include "stdafx.h"
#include "PersonalManageInfoController.h"
#include "../../../service/PersonalManageInfo/PersonalManageService.h"

PersonalManageInfoJsonVO::Wrapper PersonalManageInfoController::execQuerypersonmanageinfo(const String& xunique)
{
	if (atoi(xunique->c_str()) <= 0) {
		throw std::invalid_argument("unique is invalid");
	}
	PersonalManageService service;
	auto res = service.queryPersonalManageInfo(xunique);
	auto jvo = PersonalManageInfoJsonVO::createShared();
	jvo->success(res);
	return jvo;
}

StringJsonVO::Wrapper PersonalManageInfoController::execModifypersonmanageinfo(const PersonalManageInfoDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();
	if (dto->xname->empty() || dto->xunique->empty() || dto->xmobile->empty() || dto->xgenderType->empty()) {
		jvo->init(String("unique name mobile and genderType is needed"), RS_PARAMS_INVALID);
		return jvo;
	}
	else if (atoi(dto->xunique->c_str()) <= 0) {
		jvo->init(String("unique is invalid"), RS_PARAMS_INVALID);
		return jvo;
	}
	PersonalManageService service;
	if (service.modifyPersonalManageInfo(dto)) {
		jvo->success(dto->xunique);
	}
	else {
		jvo->fail(dto->xunique);
	}
	return jvo;
}