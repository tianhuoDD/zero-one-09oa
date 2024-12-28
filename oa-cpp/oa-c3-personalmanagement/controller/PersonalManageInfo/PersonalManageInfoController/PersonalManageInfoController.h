#pragma once
#ifndef PERSONALMANAGEINFOCONTROLLER
#define PERSONALMANAGEINFOCONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/PersonalManageInfo/PersonalManageInfoDTO.h"
#include "domain/vo/PersonalManageInfo/PersonalManageInfoVO.h"
#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class PersonalManageInfoController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(PersonalManageInfoController);
public:
	ENDPOINT_INFO(queryPersonalManageInfo) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("personmanageinfo.query.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(PersonalManageInfoJsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/personal-management/query-personal-info/{xunique}", queryPersonalManageInfo, PATH(String, xunique), execQuerypersonmanageinfo(xunique));

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("personmanageinfo.modify.summary"), modifyPersonalManageInfo, StringJsonVO::Wrapper)
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/personal-management/modify-personal-info", modifyPersonalManageInfo, BODY_DTO(PersonalManageInfoDTO::Wrapper, dto), execModifypersonmanageinfo(dto));

private:
	PersonalManageInfoJsonVO::Wrapper execQuerypersonmanageinfo(const String& xunique);
	StringJsonVO::Wrapper execModifypersonmanageinfo(const PersonalManageInfoDTO::Wrapper& dto);
};
                                                      

#include OATPP_CODEGEN_END(ApiController)

#endif // !PERSONALMANAGEINFOCONTROLLER