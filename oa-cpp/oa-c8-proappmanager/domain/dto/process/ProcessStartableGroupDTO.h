#pragma once
#ifndef _PROCESSSTARTABLEGROUP_DTO_
#define _PROCESSSTARTABLEGROUP_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ProcessStartableGroupDTO : public oatpp::DTO {
	DTO_INIT(ProcessStartableGroupDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, PROCESS_XID, "PROCESS_XID");
	API_DTO_FIELD_DEFAULT(String, xstartableGroupList, "xstartableGroupList");
	API_DTO_FIELD_DEFAULT(UInt64, xorderColumn, "xorderColumn");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSSTARTABLEGROUP_DTO_