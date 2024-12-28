#pragma once
#ifndef _PROCESSCONTROLLER_MAPPER_
#define _PROCESSCONTROLLER_MAPPER_
#include "Mapper.h"
#include "domain/do/process/ProcessControllerDO.h"


class ProcessControllerMapper : public Mapper<ProcessControllerDO> {
public:
	ProcessControllerDO mapper(ResultSet* resultSet) const override {
		ProcessControllerDO data;
		data.setPROCESS_XID(resultSet->getString("PROCESS_XID"));
		data.setXcontrollerList(resultSet->getString("xcontrollerList"));
		data.setXorderColumn(resultSet->getInt("xorderColumn"));
		return data;
	}
};

#endif // !_PROCESSCONTROLLER_MAPPER_