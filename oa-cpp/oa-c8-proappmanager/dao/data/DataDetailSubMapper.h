#pragma once
#ifndef _DATADETAILSUB_MAPPER_
#define _DATADETAILSUB_MAPPER_
#include "Mapper.h"
#include "domain/do/data/DataDetailSubDO.h"

class DataDetailSubMapper : public Mapper<DataDetailSubDO> {
public:
	DataDetailSubDO mapper(ResultSet* resultSet) const override {
		DataDetailSubDO data;
		data.setFieldStr(resultSet->getString("fieldStr"));
		return data;
	}
};

#endif // !_DATADETAILSUB_MAPPER_
