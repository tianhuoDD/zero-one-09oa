#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _USERCONTROLLER_H_
#define _USERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/menuAD/MenuADDTO.h"
#include "domain/GlobalInclude.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class MenuADController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(MenuADController);

public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addMenu) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("menu.addmenu.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/resource-management/add-menu", addMenu, BODY_DTO(MenuADDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddMenu(dto));
	}

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(deletMenu) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("menu.deletmenu.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "menu_id", ZH_WORDS_GETTER("menu.info.menu_id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/resource-management/delet-menu/{menu_id}", deletMenu, PATH(String, menu_id), execRemoveMenu(menu_id));

private:
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddMenu(const MenuADDTO::Wrapper& dto);
	
	// 3.3 演示删除数据
	StringJsonVO::Wrapper execRemoveMenu(const string& id);

};
	

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_