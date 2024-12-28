#pragma once
#ifndef _CREATEORGDTO_
#define _CREATEORGDTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//创建组织DTO
class CreateOrgDTO : public oatpp::DTO
{
	DTO_INIT(CreateOrgDTO, DTO);
	// 组织等级
	DTO_FIELD(Int32, xlevel);
	// 组织名称-必须-同一层级下要求唯一
	DTO_FIELD(String, xname);
	// 唯一编码-必须-要求唯一
	DTO_FIELD(String, xunique);
	// 组织类别列表
	// (组织类别表：没找到；组织和类别关系表：org_unit_typelist)
	//DTO_FIELD(List<String>, xtypeList);
	DTO_FIELD(String, xtypeList);
	// 组织简称
	DTO_FIELD(String, xshortName);
	// 组织描述
	DTO_FIELD(String, xdescription);
	// 管理者列表（管理者表：org_person；组织和管理者关系表：org_unit_controllerlist）
	DTO_FIELD(List<String>, xcontrollerList);
	// 上级组织
	DTO_FIELD(String, xsuperior);
	// 排序值
	DTO_FIELD(Int32, xorderNumber);
	// 组织名称拼音
	DTO_FIELD(String, xpinyin);
	// 组织名称拼音的首字母
	DTO_FIELD(String, xpinyinInitial);

	//描述
	DTO_FIELD_INFO(xlevel) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xlevel");
	}
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xname");
	}
	DTO_FIELD_INFO(xunique) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xunique");
	}
	DTO_FIELD_INFO(xtypeList) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xtypeList");
	}
	DTO_FIELD_INFO(xshortName) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xshortName");
	}
	DTO_FIELD_INFO(xdescription) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xdescription");
	}
	DTO_FIELD_INFO(xcontrollerList) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xcontrollerList");
	}
	DTO_FIELD_INFO(xsuperior) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xsuperior");
	}
	DTO_FIELD_INFO(xorderNumber) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xorderNumber");
	}
	DTO_FIELD_INFO(xpinyin) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xpinyin");
	}
	DTO_FIELD_INFO(xpinyinInitial) {
		info->description = ZH_WORDS_GETTER("post.createOrg.xpinyinInitial");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CREATEORGDTO_