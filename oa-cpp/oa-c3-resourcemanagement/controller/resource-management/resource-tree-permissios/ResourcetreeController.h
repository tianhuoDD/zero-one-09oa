#pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/resource-management/resource-tree-permissions/ResourcetreeVO.h"
#include "domain/query/resource-management/Resourcetreequery.h"
#include "dao/resource-tree-permissios/ResourcetreeDAO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ResourcetreeController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ResourcetreeController);
	// 3 定义接口
public:
	// 定义查询用户菜单接口端点描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("resource.get.permissions"), queryMenu, PermissionsJsonVO::Wrapper);
	// 定义查询用户菜单接口端点处理
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "resource-management/resource-tree-permissions", queryMenu, executeQuerypermissions(authObject->getPayload()))
private:
	// 执行获取个人信息
	PermissionsJsonVO::Wrapper executeQuerypermissions(const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_