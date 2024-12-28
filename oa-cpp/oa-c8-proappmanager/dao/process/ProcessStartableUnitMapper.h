#pragma once
#ifndef _PROCESSSTARTABLEUNIT_MAPPER_
#define _PROCESSSTARTABLEUNIT_MAPPER_
#include "Mapper.h"
#include "domain/do/process/ProcessStartableUnitDO.h"


class ProcessStartableUnitMapper : public Mapper<ProcessStartableUnitDO> {
public:
	ProcessStartableUnitDO mapper(ResultSet* resultSet) const override {
		ProcessStartableUnitDO data;
		data.setPROCESS_XID(resultSet->getString("PROCESS_XID"));
		data.setXstartableUnitList(resultSet->getString("xstartableUnitList"));
		data.setXorderColumn(resultSet->getInt("xorderColumn"));
		return data;
	}
};

#endif // !_PROCESSSTARTABLEUNIT_MAPPER_