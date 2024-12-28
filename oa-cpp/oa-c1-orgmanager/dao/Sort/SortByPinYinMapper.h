#pragma once
#ifndef _SortByPinYin_MAPPER_
#define _SortByPinYin_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Sort/SortByPinYinDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class SortByPinYinMapper : public Mapper<SortByPinYinDO>
{
public:
	SortByPinYinDO mapper(ResultSet* resultSet) const override
	{
		SortByPinYinDO data;
		data.setXid(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setShuxing(resultSet->getString(3));
		data.setValue(resultSet->getInt(4));
		data.setMiaoshu(resultSet->getString(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_