#pragma once
#pragma once

#ifndef _FORMLISTVO_H_
#define _FORMLISTVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/FormList/FormListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FormListJsonVO : public JsonVO<FormListDTO::Wrapper> {
	DTO_INIT(FormListJsonVO, JsonVO<FormListDTO::Wrapper>);
};

// ·ÖÒ³

#include OATPP_CODEGEN_END(DTO)

#endif // !_FORM_TEMPLATE_VO_
