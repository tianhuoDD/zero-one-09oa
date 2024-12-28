#pragma once


#ifndef _COLUMNSINFO_MAPPER_
#define _COLUMNSINFO_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/column/setting/ColumnsInfoDO.h"


class ColumnsInfoMapper : public Mapper<ColumnsInfoDO> {
	
	

public: 
	ColumnsInfoDO mapper(ResultSet* resultSet) const override {

		ColumnsInfoDO data;
		data.setXid(resultSet->getString(1));
		std::cout <<" data.getXid()=" << data.getXid()<<std::endl;
		data.setXappName(resultSet->getString(2));
		std::cout << " data.getString()=" << data.getXappName()<<std::endl;

		return data;
	}
};




#endif // !_COLUMNSINFO_MAPPER_
