#pragma once

#ifndef _FILERESPONSEVO_H_
#define _FILERESPONSEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/file/FileResponseDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ImportResponseVO : public JsonVO<ImportResponseDTO::Wrapper>
{
	DTO_INIT(ImportResponseVO, JsonVO<ImportResponseDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // ! _FILERESPONSEVO_H_
