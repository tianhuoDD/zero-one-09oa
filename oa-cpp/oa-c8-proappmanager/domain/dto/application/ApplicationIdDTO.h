#pragma once
#ifndef _APPLICATION_ID_DTO_
#define _APPLICATION_ID_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class ApplicationIdDTO : public oatpp::DTO {
	DTO_INIT(ApplicationIdDTO, DTO);

	DTO_FIELD(String,id );

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATION_ID_DTO_
