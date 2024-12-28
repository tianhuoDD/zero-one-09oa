#pragma once

#ifndef _CHANGEPERSONPROFILECONTROLLER_H_
#define _CHANGEPERSONPROFILECONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "stdafx.h"
#include "domain/vo/ChangePersonProfile/ChangePersonProfileVO.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "Macros.h"
#include "domain/query/ChangePersonProfile/ChangePersonProfileQuery.h"
#include "domain/dto/ChangePersonProfile/ChangePersonProfileDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
using namespace oatpp;
/**
 * 用户控制器，处理用户相关的API请求
 */
class ChangePersonProfileController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
    // 2 定义控制器访问入口
    API_ACCESS_DECLARE(ChangePersonProfileController);

public:

	// 定义修改用户信息端点描述
	ENDPOINT_INFO(modifyUser) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("changeprofile.user.summary"), StringJsonVO::Wrapper);
		// 定义修改查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("changeprofile.user.field.id"), "a", false);
		// 定义二进制流请求方式，用于选择上传文件
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
	}
	// 定义修改用户信息端点处理（注意：此方式只支持单文件上传，并且更新字段不是很多的场景使用）
	ENDPOINT(API_M_POST, "/personal-management/modify-icon", modifyUser, BODY_STRING(String, fileBody), QUERIES(QueryParams, qps), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(dto, ChangePersonProfileDTO, qps);
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(executeModifyUser(fileBody, dto));
	}
private:
    // 处理更换头像的逻辑
    StringJsonVO::Wrapper executeModifyUser(const String& fileBody, const ChangePersonProfileDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 
