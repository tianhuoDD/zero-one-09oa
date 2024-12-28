#pragma once
#ifndef _PROCESSSTARTABLEUNIT_DTO_
#define _PROCESSSTARTABLEUNIT_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ProcessStartableUnitDTO : public oatpp::DTO {
	DTO_INIT(ProcessStartableUnitDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, PROCESS_XID, "PROCESS_XID");
	API_DTO_FIELD_DEFAULT(String, xstartableUnitList, "xstartableUnitList");
	API_DTO_FIELD_DEFAULT(UInt64, xorderColumn, "xorderColumn");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSSTARTABLEUNIT_DTO_