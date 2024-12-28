#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 26�� ������ 09:37:55 CST
*/
#ifndef _REMOVEPERSON_MAPPER_
#define _REMOVEPERSON_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/put/OrgGroupPersonlistDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class RemovePersonMapper : public Mapper<OrgGroupPersonlistDO>
{
public:
	OrgGroupPersonlistDO mapper(ResultSet* resultSet) const override
	{
		OrgGroupPersonlistDO data;
		data.setGroup_xid(resultSet->getString(1));
		data.setXperson_list(resultSet->getString(2));
		data.setXorder_column(resultSet->getInt(3));
		return data;
	}
};

#endif // !_REMOVEPERSON_MAPPER_