#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/20 18:03:17

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
#ifndef _SYSSETTINGCONTROLLER_H_
#define _SYSSETTINGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/system/setting/SystemInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class SysSettingController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(SysSettingController);
public: 
	// 修改系统名称
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sys.setting.put.name"), modifySystemName, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/base/system_name", modifySystemName, BODY_DTO(SystemInfoDTO::Wrapper, dto), executeModifySystemName(dto, authObject->getPayload()));

	// 修改系统副标题
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sys.setting.put.subtitle"), modifySystemSubtitle, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/base/system_subtitle", modifySystemSubtitle, BODY_DTO(SystemInfoDTO::Wrapper, dto), executeModifySystemSubtitle(dto,authObject->getPayload()));

	
private: // 定义接口执行函数
	//执行修改系统名称
	StringJsonVO::Wrapper executeModifySystemSubtitle(const SystemInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	//执行修改系统副标题
	StringJsonVO::Wrapper executeModifySystemName(const SystemInfoDTO::Wrapper& dto, const PayloadDTO& payload);
};



#include OATPP_CODEGEN_END(ApiController)

#endif // !_SYSSETTINGCONTROLLER_H_