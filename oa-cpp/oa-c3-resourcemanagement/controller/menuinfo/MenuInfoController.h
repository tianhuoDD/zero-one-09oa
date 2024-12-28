#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/20 16:17:49

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
#ifndef _MENUINFOCONTROLLER_H_
#define _MENUINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/menuinfo/MenuInfoVO.h"
#include "domain/dto/menuinfo/MenuInfoDTO.h"
#include "domain/query/menuinfo/MenuInfoQuery.h"
#include "../ApiDeclarativeServicesHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MenuInfoController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(MenuInfoController);
public: // 定义接口
	// 获取菜单信息接口
	//// 1.1 定义查询接口处理
	////* 严格按照arch-demo书写的方式  *下面这行代码的参数依次是 接口地址 + 接口的名字也就是方法名 + 查询参数
	//ENDPOINT_INFO(queryMenuInfo) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("menuinfo.get.summary"), MenuInfoJsonVO::Wrapper);
	//	// 定义其他路径参数说明
	//	API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("menuinfo.field.id"), 007, true);
	//}
	//// 1.2 定义查询接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/query-menuinfo/queryone", queryMenuInfo, QUERY(UInt64, id), executeQueryMenuInfo(id, authObject->getPayload()));

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryMenuInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("menuinfo.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MenuInfoJsonVO);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "resource-management/query-menuinfo/queryone/{menu_id}", queryMenuInfo, PATH(String, menu_id), API_HANDLER_AUTH_PARAME) {
		// 从请求头里获取id
		//String menu_id = authObject->getPayload().getId();
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryMenuInfo(menu_id));
	}


	
	// *修改菜单信息接口（修改接口主要是该边了接口返回值的类型改成了StringJsonVO，下边private也跟着改变，还有controller.cpp里的函数处理后的返回类型）（主要就是这一点有改变）
	// 2.1 定义修改菜单信息接口描述 *下面这行代码的参数依次是 中文注释 + 接口的名字也就是方法名 + 响应结果
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("menuinfo.put.summary"), modifyMenuInfo, StringJsonVO::Wrapper);  //*StringJsonVO变成StringJsonVO 就是返回一个成功时的唯一标识符 比如1 ；如果是用StringJsonVO那就是返回一个该数据的menu_id
	// 2.2 定义修改菜单信息接口处理 *下面这行代码的参数依次是 接口路径 + 接口的名字也就是方法名 + 修改时用到的DTO + 修改操作对应的执行函数
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "resource-management/post-menuinfo", modifyMenuInfo, BODY_DTO(MenuInfoDTO::Wrapper, dto), executeModifyMenuInfo(dto));



private: // 定义接口执行函数
	// 执行获取菜单信息 *传入menu_id类型参数
	MenuInfoJsonVO::Wrapper executeQueryMenuInfo(const String& menu_id);
	// 执行修改菜单信息 *传入DTO类型参数
	StringJsonVO::Wrapper executeModifyMenuInfo(const MenuInfoDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MENUINFOCONTROLLER_H_