#pragma once
#ifndef _OrgUnitIdentityTREEVO_H_
#define _OrgUnitIdentityTREEVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/OrgUnitTree/OrgUnitIdentityTreeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例组织成员显示JsonVO对象，用于响应给前端
 */
class OrgUnitIdentityTreeJsonVO : public JsonVO<List<OrgUnitIdentityTreeDTO::Wrapper>>
{
	DTO_INIT(OrgUnitIdentityTreeJsonVO, JsonVO<List<OrgUnitIdentityTreeDTO::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	OrgUnitIdentityTreeJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OrgUnitIdentityTREEVO_H_
