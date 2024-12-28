#pragma once
#ifndef _PROCESSINFO_VO_
#define _PROCESSINFO_VO_

#include "domain/GlobalInclude.h"
#include "domain/dto/process/ProcessInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//class ProcessInfoVO : public JsonVO<ProcessInfoDTO::Wrapper> {
//	DTO_INIT(ProcessInfoVO, JsonVO<ProcessInfoDTO::Wrapper>);
//};

class ProcessInfoJsonVO : public JsonVO<ProcessInfoDTO::Wrapper> {
	DTO_INIT(ProcessInfoJsonVO, JsonVO<ProcessInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSINFO_VO_
