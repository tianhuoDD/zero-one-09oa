#pragma 
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/21 23:21:18

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
#ifndef _SELECTORGNAMETREECONTROLLER_H_
#define _SELECTORGNAMETREECONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/OrgNameTreeVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)

class SelectOrgNameTreeController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(SelectOrgNameTreeController);
public: // 定义接口

	 //定义查询组织名称接口端点描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("organization.query-allname.summary"), queryOrgName, OrgNameTreeJsonVO::Wrapper);
	 //定义查询组织名称接口端点处理  没写文件夹前端定位的文件描述暂定/orgmanagment
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/c1-org/orgmanagment/SelectOrgNameTree", queryOrgName, executeQueryOrgName(authObject->getPayload()))

private: // 定义接口执行函数
	OrgNameTreeJsonVO::Wrapper executeQueryOrgName(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SELECTORGNAMETREECONTROLLER_H_