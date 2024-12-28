#pragma once

#ifndef _APPLICATIONPROPERTIES_VO_
#define _APPLICATIONPROPERTIES_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/application/ApplicationPropertiesDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Ӧ������JsonVO��������Ӧ���ͻ��˵�Json����
 */
class ApplicationPropertiesJsonVO : public JsonVO<ApplicationPropertiesDTO::Wrapper>
{
	DTO_INIT(ApplicationPropertiesJsonVO, JsonVO<ApplicationPropertiesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATIONPROPERTIES_VO_
