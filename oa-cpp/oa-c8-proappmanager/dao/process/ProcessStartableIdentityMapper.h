#pragma once
#ifndef _PROCESSSTARTABLEIDENTITY_MAPPER_
#define _PROCESSSTARTABLEIDENTITY_MAPPER_
#include "Mapper.h"
#include "domain/do/process/ProcessStartableIdentityDO.h"


class ProcessStartableIdentityMapper : public Mapper<ProcessStartableIdentityDO> {
public:
	ProcessStartableIdentityDO mapper(ResultSet* resultSet) const override {
		ProcessStartableIdentityDO data;
		data.setPROCESS_XID(resultSet->getString("PROCESS_XID"));
		data.setXstartableIdentityList(resultSet->getString("xstartableIdentityList"));
		data.setXorderColumn(resultSet->getInt("xorderColumn"));
		return data;
	}
};

#endif // !_PROCESSSTARTABLEIDENTITY_MAPPER_