#pragma once

#ifndef _FORMTEMPLATEDETAILSVO_H_
#define _FORMTEMPLATEDETAILSVO_H_

#include "../GlobalInclude.h"
#include "domain/dto/PageDTO.h"
#include "domain/dto/FormTemplateDetailsDTO.h"
#include "domain/dto/FormTemplateDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FormTemplateDetailsJsonVO : public JsonVO<FormTemplateDetailsDTO::Wrapper>
{
	DTO_INIT(FormTemplateDetailsJsonVO, JsonVO<FormTemplateDetailsDTO::Wrapper>);
};

class FormTemplateDetailsPageJsonVO :public JsonVO<FormTemplatePageDTO::Wrapper>
{
	DTO_INIT(FormTemplateDetailsPageJsonVO, JsonVO<FormTemplatePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif