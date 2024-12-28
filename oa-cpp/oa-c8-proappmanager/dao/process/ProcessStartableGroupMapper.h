#pragma once
#ifndef _PROCESSSTARTABLEGROUP_MAPPER_
#define _PROCESSSTARTABLEGROUP_MAPPER_
#include "Mapper.h"
#include "domain/do/process/ProcessStartableGroupDO.h"


class ProcessStartableGroupMapper : public Mapper<ProcessStartableGroupDO> {
public:
	ProcessStartableGroupDO mapper(ResultSet* resultSet) const override {
		ProcessStartableGroupDO data;
		data.setPROCESS_XID(resultSet->getString("PROCESS_XID"));
		data.setXstartableGroupList(resultSet->getString("xstartableGroupList"));
		data.setXorderColumn(resultSet->getInt("xorderColumn"));
		return data;
	}
};

#endif // !_PROCESSSTARTABLEGROUP_MAPPER_