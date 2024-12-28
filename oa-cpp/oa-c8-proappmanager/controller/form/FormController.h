#pragma once
#ifndef _FORMCONTROLLER_H
#define _FORMCONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/form/FormListDTO.h"

#include "domain/vo/form/FormCategoryVO.h"
#include "domain/vo/form/FormListVO.h"
#include "domain/vo/form/FormInfoVO.h"
#include "domain/query/form/FormListQuery.h"
#include "domain/dto/form/OperateFormDTO.h"

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class FormController :public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(FormController);//宏定义 为FormController 类添加构造函数和 createShared 方法

public:// 定义接口

	//表单详情
	//获取表单详情接口描述
	ENDPOINT_INFO(queryFormInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.info.get.summary"));
		//// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FormInfoJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("form.field.xid"), "1234", true);
	}
	// 定义获取表单详情接口处理
	ENDPOINT(API_M_GET, "/process-app-manager/form/query-info", queryFormInfo, QUERY(String, xid), API_HANDLER_AUTH_PARAME) //API_HANDLER_AUTH_PARAME
	{

		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFormInfo(xid));
	}


	//表单列表
	//获取表单列表接口描述
	ENDPOINT_INFO(queryFormList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.list.get.summary"));
		//// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		 //定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FormListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xcategory", ZH_WORDS_GETTER("form.field.xcategory"),"111", false);//所属分类
		API_DEF_ADD_QUERY_PARAMS(String, "xapplication", ZH_WORDS_GETTER("form.field.xapplication"),"111", true);//所属应用
	}
	// 定义获取表单列表接口处理
	ENDPOINT(API_M_GET, "/process-app-manager/form/query-list", queryFormList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(Query, FormListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFormList(Query));
	}

	//表单类型及数量
	//获取表单类型及数量接口描述
	ENDPOINT_INFO(queryFormCategory) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.category.get.summary"));
		//// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FormCategoryJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xapplication", ZH_WORDS_GETTER("form.field.xapplication"), "111", true);//所属应用
	}
	// 定义获取表单列表接口处理
	ENDPOINT(API_M_GET, "/process-app-manager/form/query-category", queryFormCategory, QUERY(String, xapplication), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFormCategory(xapplication));
	}

	// 创建表单
	ENDPOINT_INFO(addForm) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.add.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义创建表单列表接口处理
	ENDPOINT(API_M_POST, "/process-app-manager/form/add", addForm, BODY_DTO(OperateFormDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddForm(dto, authObject->getPayload()));
	}

	// 修改表单
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("form.modify.get.summary"), modifyForm, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/process-app-manager/form/modify", modifyForm, BODY_DTO(OperateFormDTO::Wrapper, dto), execModifyForm(dto, authObject->getPayload()));
	
	// 删除表单
	ENDPOINT_INFO(removeForm) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("form.delete.get.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("form.field.id"), "", true);
	}
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/process-app-manager/form/remove/{id}", removeForm, PATH(String, id), execRemoveForm(id));

private: // 定义接口执行函数

	// 执行获取表单详情函数
	FormInfoJsonVO::Wrapper execQueryFormInfo(const String& xid);

	// 执行获取表单列表函数
	FormListPageJsonVO::Wrapper execQueryFormList(const FormListQuery::Wrapper& userQuery);

	// 执行获取表单类型及数量函数
	FormCategoryJsonVO::Wrapper execQueryFormCategory(const String& xapplication);

	// 添加表单
	StringJsonVO::Wrapper execAddForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改表单
	StringJsonVO::Wrapper execModifyForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload);
	// 删除表单
	StringJsonVO::Wrapper execRemoveForm(const String& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FORMCONTROLLER_H