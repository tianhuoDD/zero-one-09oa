#pragma once
#ifndef _PERSONALMANAGEMENTCONTROLLER_H_
#define _PERSONALMANAGEMENTCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
//导入查询角色相关头文件
#include "domain/vo/Orgmanagement/PersonalManagement/RoleInfoVO.h"
#include "domain/query/OrgManagement/PersonalManagement/RoleInfoQuery.h"
#include "service/OrgManagement/PersonalManagement/RoleInfoService.h"
//导入查询职务相关头文件
#include "domain/vo/Orgmanagement/PersonalManagement/SearchDutyVO.h"
#include "service/OrgManagement/PersonalManagement/SearchDutyService.h"
//导入设置职务相关头文件
#include "domain/dto/OrgManagement/PersonalManagement/DutySettingDTO.h"
#include "service/OrgManagement/PersonalManagement/DutySettingService.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class PersonManagementController :public oatpp::web::server::api::ApiController {
	//定义控制器访问入口
	API_ACCESS_DECLARE(PersonManagementController);
public://定义接口
	//定义修改职务接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("domain.dto.OrgManagement.PersonalManagement.DutySetting.summary"), modifyDuty, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/personal-management/modify-duty", modifyDuty, BODY_DTO(DutySettingDTO::Wrapper, dto), execModifyDuty(dto));
	//定义查询职务接口
	ENDPOINT_INFO(queryDuty) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.SearchDuty.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SearchDutyJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.SearchDuty.Xname"), "duty", true);

	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/personal-management/query-duty", queryDuty, QUERY(String, xname), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDuty(xname));
	}

	//定义获取个人角色接口
	ENDPOINT_INFO(queryRole) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.RoleInfo.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RoleInfoPageJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.RoleInfo.Xid"), "xid", true);

	}
	// 定义获取个人角色处理
	ENDPOINT(API_M_GET, "/personal-management/query-role", queryRole, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		
		API_HANDLER_QUERY_PARAM(roleinfoQuery, RoleInfoQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRole(roleinfoQuery));
	}
private://定义接口执行函数
	Uint64JsonVO::Wrapper execModifyDuty(const DutySettingDTO::Wrapper& dto);
	SearchDutyJsonVO::Wrapper execQueryDuty(const String& xname);
	RoleInfoPageJsonVO::Wrapper execQueryRole(const RoleInfoQuery::Wrapper& roleinfoQuery);
};
#include OATPP_CODEGEN_END(ApiController)
#endif
