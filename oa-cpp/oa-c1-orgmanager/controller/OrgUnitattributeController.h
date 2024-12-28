/*
 Copyright Zero One Star. All rights reserved.

 @Author: UptoFate
 @Date: 2024/10/22 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _ORGUNITATTRIBUTE_CONTROLLER_
#define _ORGUNITATTRIBUTE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"
#include "domain/vo/OrgUnitattributeVO.h"
#include "domain/query/OrgUnitattributeQuery.h"
#include "domain/dto/OrgUnitattributeDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class OrgUnitattributeController : public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(OrgUnitattributeController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryOrgUnitattribute) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("org.unitattribute.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OrgUnitattributePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c1-org/queryOrgUnitattribute", queryOrgUnitattribute, QUERIES(QueryParams, Params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, OrgUnitattributeQuery, Params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryOrgUnitattribute(query, authObject->getPayload()));
	}

		// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeOrgUnitattribute) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("org.unitattribute.delete.summary"));
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("org.unitattribute.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(StringJsonVO::Wrapper, "Xids", ZH_WORDS_GETTER("org.unitattribute.delete.summary"), "[\"1\", \"2\"]", true);
		// 
		//参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "Xids", ZH_WORDS_GETTER("org.unitattribute.delete.summary"), "[\"1\", \"2\"]", true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c1-org/removeOrgUnitattribute", removeOrgUnitattribute, BODY_DTO(OrgUnitattributeQuery::Wrapper,dto), execRemoveOrgUnitattribute(dto));

private:
	OrgUnitattributePageJsonVO::Wrapper execQueryOrgUnitattribute(const OrgUnitattributeQuery::Wrapper& query, const PayloadDTO& payload);

	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveOrgUnitattribute(const OrgUnitattributeQuery::Wrapper& id);

};



#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGUNITATTRIBUTE_CONTROLLER_
