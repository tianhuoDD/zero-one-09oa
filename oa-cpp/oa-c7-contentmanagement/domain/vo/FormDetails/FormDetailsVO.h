#pragma once
#pragma once
#pragma once

#ifndef _FORMDETAILSVO_H_
#define _FORDETAILSVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/FormDetails/FormDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FormDetailsJsonVO : public JsonVO<FormDetailsDTO::Wrapper> {
	DTO_INIT(FormDetailsJsonVO, JsonVO<FormDetailsDTO::Wrapper>);
};

// ·ÖÒ³

#include OATPP_CODEGEN_END(DTO)

#endif // !_FORM_TEMPLATE_VO_
