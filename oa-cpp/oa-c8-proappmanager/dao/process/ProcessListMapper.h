#pragma once
#ifndef _PROCESSLIST_MAPPER_
#define _PROCESSLIST_MAPPER_

#include "Mapper.h"
#include "domain/do/process/ProcessListDO.h"

/**
 * �����б����ݿ�ʵ��ӳ����
 */
class ProcessListMapper : public Mapper<ProcessListDO> {
public:
	ProcessListDO mapper(ResultSet* resultSet) const override {
		ProcessListDO data;
		int i = 0;
		data.setXid(resultSet->getString(++i));
		data.setXcategory(resultSet->getString(++i));
		data.setXname(resultSet->getString(++i));
		data.setXalias(resultSet->getString(++i));
		data.setXdescription(resultSet->getString(++i));
		data.setXlastUpdateTime(resultSet->getString(++i));
		return data;
	}
};

#endif // !_PROCESSLIST_MAPPER_
