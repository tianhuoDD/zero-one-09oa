#pragma once

#ifndef _APPLICATIONPROPERTIES_VO_
#define _APPLICATIONPROPERTIES_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/application/ApplicationPropertiesDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 应用属性JsonVO，用于响应给客户端的Json对象
 */
class ApplicationPropertiesJsonVO : public JsonVO<ApplicationPropertiesDTO::Wrapper>
{
	DTO_INIT(ApplicationPropertiesJsonVO, JsonVO<ApplicationPropertiesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATIONPROPERTIES_VO_
