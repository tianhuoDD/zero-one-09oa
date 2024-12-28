#pragma once
#ifndef _PROCESSCONTROLLER_DTO_
#define _PROCESSCONTROLLER_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ProcessControllerDTO : public oatpp::DTO {
	DTO_INIT(ProcessControllerDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, PROCESS_XID, "PROCESS_XID");
	API_DTO_FIELD_DEFAULT(String, xcontrollerList, "xcontrollerList");
	API_DTO_FIELD_DEFAULT(UInt64, xorderColumn, "xorderColumn");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSCONTROLLER_DTO_