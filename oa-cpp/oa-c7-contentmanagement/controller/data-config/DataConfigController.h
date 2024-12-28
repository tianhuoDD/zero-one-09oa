#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/21 21:14:51

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
#ifndef _ADDDATACONFIGCONTROLLER_H_
#define _ADDDATACONFIGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/data-config/DataConfigVO.h"
#include "domain/dto/data-config/DataConfigDTO.h"
#include "../../../lib-oatpp/include/ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DataConfigController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(DataConfigController);
public: // 定义接口
	 //获取数据配置详情接口
	ENDPOINT_INFO(queryDataConfig) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("data-config.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DataConfigJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("data-config.field.xid"), "x40b75ee6-3348-405d-a854-be99e7e9ab13id", true);
	}
	ENDPOINT(API_M_GET, "/data/get-dataconfig", queryDataConfig, QUERY(String,id), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDataConfig(id));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addDataConfig) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("data-config.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/data/add-dataconfig", addDataConfig, BODY_DTO(AddDataConfigDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDataConfig(dto));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("data-config.put.summary"), modifyDataConfig, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/data/modify-dataconfig", modifyDataConfig, BODY_DTO(ModifyDataConfigDTO::Wrapper, dto), execModifyDataConfig(dto));

private: // 定义接口执行函数
	// 执行获取数据配置详情
	DataConfigJsonVO::Wrapper execQueryDataConfig(const String& id);

	//执行新增数据配置
	StringJsonVO::Wrapper execAddDataConfig(const AddDataConfigDTO::Wrapper& dto);

	//执行修改数据配置
	StringJsonVO::Wrapper execModifyDataConfig(const ModifyDataConfigDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ADDDATACONFIGCONTROLLER_H_
