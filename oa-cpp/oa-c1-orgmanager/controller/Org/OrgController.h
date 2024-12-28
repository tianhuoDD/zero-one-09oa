#pragma once
#ifndef _ORGCONTROLLER_H_
#define _ORGCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Org/CreateOrgDTO.h"
#include "domain/dto/Org/DeleteOrgDTO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class OrgController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(OrgController);
public:
	//接口定义------------------------------------------------------------------------------
	//添加组织
	ENDPOINT(API_M_POST, "/c1-org/orgmanagment/createOrg", createOrg, BODY_DTO(CreateOrgDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		//响应结果
		API_HANDLER_RESP_VO(execCreateOrg(dto));
	}
	//删除组织
	//ENDPOINT(API_M_POST, "/orgmanagment/deleteOrg", deleteOrg, BODY_DTO(DeleteOrgDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	ENDPOINT(API_M_POST, "/c1-org/orgmanagment/deleteOrg", deleteOrg, BODY_DTO(DeleteOrgDTO::Wrapper, dto))
	{
		//响应结果
		API_HANDLER_RESP_VO(execDeleteOrg(dto));
	}

	//接口描述------------------------------------------------------------------------------
	//添加组织
	ENDPOINT_INFO(createOrg)
	{
		API_DEF_ADD_AUTH();
		//接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("post.createOrg.summary"));
		//响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Int32JsonVO);
		//参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "xlevel", ZH_WORDS_GETTER("post.createOrg.xlevel"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("post.createOrg.xname"), "first_org", true);
		API_DEF_ADD_QUERY_PARAMS(String, "xunique", ZH_WORDS_GETTER("post.createOrg.xunique"), "10001", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "xtypeList", ZH_WORDS_GETTER("post.createOrg.xtypeList"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xtypeList", ZH_WORDS_GETTER("post.createOrg.xtypeList"), "", false);
		/*info->queryParams.add<List<String>>("xtypeList").description = ZH_WORDS_GETTER("post.createOrg.xtypeList");
		info->queryParams["xtypeList"].addExample("default", List<String>({ "company", "others" }));
		info->queryParams["xtypeList"].required = false;*/
		API_DEF_ADD_QUERY_PARAMS(String, "xshortName", ZH_WORDS_GETTER("post.createOrg.xshortName"), "first_org_shortName", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xdescription", ZH_WORDS_GETTER("post.createOrg.xdescription"), "first_org_xdescription", false);
		info->queryParams.add<List<String>>("xcontrollerList").description = ZH_WORDS_GETTER("post.createOrg.xcontrollerList");
		info->queryParams["xcontrollerList"].addExample("default", List<String>({ "001", "002" }));
		info->queryParams["xcontrollerList"].required = false;
		API_DEF_ADD_QUERY_PARAMS(String, "xsuperior", ZH_WORDS_GETTER("post.createOrg.xsuperior"), " ", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "xorderNumber", ZH_WORDS_GETTER("post.createOrg.xorderNumber"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "xpinyin", ZH_WORDS_GETTER("post.createOrg.xpinyin"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(Int32, "xpinyinInitial", ZH_WORDS_GETTER("post.createOrg.xpinyinInitial"), 1, true);
	}
	//删除组织
	ENDPOINT_INFO(deleteOrg)
	{
		//API_DEF_ADD_AUTH();
		//接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("post.deleteOrg.summary"));
		//响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Int32JsonVO);
		//参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("post.deleteOrg.xid"), "2ef2bf67-99cb-11ef-8bf4-00e04c81ef62", true);
		/*info->queryParams.add<List<String>>("xuniqueList").description = ZH_WORDS_GETTER("post.deleteOrg.xuniqueList");
		info->queryParams["xtypeList"].addExample("default", List<String>({ "10001", "10002" }));
		info->queryParams["xtypeList"].required = true;*/
	}

private:
	Int32JsonVO::Wrapper execCreateOrg(const CreateOrgDTO::Wrapper& dto);
	Int32JsonVO::Wrapper execDeleteOrg(const DeleteOrgDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _ORGCONTROLLER_H_