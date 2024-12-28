#pragma once
#ifndef _ORGUNITTREECONTROLLER_H_
#define _ORGUNITTREECONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/OrgUnitTree/OrgUnitIdentityTreeVO.h"
#include "domain/vo/OrgUnitTree/OrgUnitDutyTreeVO.h"
#include "domain/do/OrgUnitTree/OrgUnitTreeDO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)

class OrgUnitTreeController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(OrgUnitTreeController);

public:
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("orgunit.query-orgunit.summary"), queryOrgUnitIdentityTree, OrgUnitIdentityTreeJsonVO::Wrapper);
    API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/c1-org/orgunit/query-orgunit-members", queryOrgUnitIdentityTree, executeQueryOrgUnitIdentityTree(authObject->getPayload()));

    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("orgunitduty.query-orgunitduty.summary"), queryOrgUnitDutyTree, OrgUnitDutyTreeJsonVO::Wrapper);
    API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/c1-org/orgunit/query-orgunit-duties", queryOrgUnitDutyTree, executeQueryOrgUnitDutyTree(authObject->getPayload()));

private:
    OrgUnitIdentityTreeJsonVO::Wrapper executeQueryOrgUnitIdentityTree(const PayloadDTO& payload);
    OrgUnitDutyTreeJsonVO::Wrapper executeQueryOrgUnitDutyTree(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGUNITTREECONTROLLER_H_
