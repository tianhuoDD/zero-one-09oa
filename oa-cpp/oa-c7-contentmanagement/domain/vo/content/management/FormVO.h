#pragma once
#ifndef _FORM_VO_
#define _FORM_VO_
#include "../../../GlobalInclude.h"
#include "../../../dto/content/management/GetFormDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class FormJsonVO : public JsonVO<GetFormDTO::Wrapper> {
	DTO_INIT(FormJsonVO, JsonVO<GetFormDTO::Wrapper>);
};

class FormPageJsonVO : public JsonVO<GetFormPageDTO::Wrapper> {
	DTO_INIT(FormPageJsonVO, JsonVO<GetFormPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FORM_VO_