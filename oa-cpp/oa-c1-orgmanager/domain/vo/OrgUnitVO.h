#pragma once
#ifndef _ORGUNIT_VO_
#define _ORGUNIT_VO_
#include "../GlobalInclude.h"
#include "../dto/OrgUnitDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class OrgUnitJsonVO : public JsonVO<OrgUnitDTO::Wrapper> {
	DTO_INIT(OrgUnitJsonVO, JsonVO<OrgUnitDTO::Wrapper>);
};
/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class OrgUnitPageJsonVO : public JsonVO<OrgUnitPageDTO::Wrapper> {
	DTO_INIT(OrgUnitPageJsonVO, JsonVO<OrgUnitPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_ORGUNIT_VO_