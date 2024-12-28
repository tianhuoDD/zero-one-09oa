#pragma once
#ifndef _PROCESSSTARTABLEIDENTITY_DTO_
#define _PROCESSSTARTABLEIDENTITY_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ProcessStartableIdentityDTO : public oatpp::DTO {
	DTO_INIT(ProcessStartableIdentityDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, PROCESS_XID, "PROCESS_XID");
	API_DTO_FIELD_DEFAULT(String, xstartableIdentityList, "xstartableIdentityList");
	API_DTO_FIELD_DEFAULT(UInt64, xorderColumn, "xorderColumn");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSSTARTABLEIDENTITY_DTO_