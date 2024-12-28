/*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif
 @Date: 2024/10/19 17:04:30

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
#ifndef _PERSONCONTROLLER_H_
#define _PERSONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/Person/PersonInfoVO.h"
#include "domain/query/PersonQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PersonController : public oatpp::web::server::api::ApiController
{
public: // 定义接口
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PersonController);
	//	获取人员名称列表
	ENDPOINT_INFO(queryPerson) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("person.query-person.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PersonInfoPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("person.query-person.name"), "R", true);
	}

	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/person/query-preson-name", queryPerson, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(perQuery, PersonQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execcuteQueryPerson(perQuery));
	}
	//获取组织成员名称接口


private: // 定义接口执行函数
	PersonInfoPageJsonVO::Wrapper execcuteQueryPerson(const PersonQuery::Wrapper& perQuery);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PERSONCONTROLLER_H_