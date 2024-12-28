#pragma once
#pragma once
#pragma once

#ifndef _DATALISTVO_H_
#define _DATALISTVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/DataList/DataListDTO.h"
#include "domain/dto/DataDetails/DataDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DataListJsonVO : public JsonVO<DataListDTO::Wrapper> {
	DTO_INIT(DataListJsonVO, JsonVO<DataListDTO::Wrapper>);
};

// ·ÖÒ³
class DataDetailsJsonVO : public JsonVO<DataDetailsDTO::Wrapper> {
	DTO_INIT(DataDetailsJsonVO, JsonVO<DataDetailsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FORM_TEMPLATE_VO_
