#pragma once
#ifndef _GROUP_MAPPER_
#define _GROUP_MAPPER_

#include "Mapper.h"
#include "../../domain/do/put/GroupDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class GroupMapper : public Mapper<GroupDO>
{
public:
	GroupDO mapper(ResultSet* resultSet) const override
	{
		GroupDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setInfo(resultSet->getString(3));
		return data;
	}
};

#endif // !_GROUP_MAPPER_