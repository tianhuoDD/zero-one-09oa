#pragma once
#ifndef _PROCESSTYPES_MAPPER_
#define _PROCESSTYPES_MAPPER_

#include "Mapper.h"
#include "domain/do/process/ProcessTypesDO.h"
#include "domain/do/process/ProcessDO.h"

/**
 * 流程类型Mapper
 */
class ProcessTypesMapper : public Mapper<ProcessTypesDO> {
public:
	ProcessTypesDO mapper(ResultSet* resultSet) const override {
		ProcessTypesDO data;
		data.setXcategory(resultSet->getString(1));
		data.setContainNums(resultSet->getInt(2));
		return data;
	}
};

#endif // !_PROCESSTYPES_MAPPER_
