#pragma once

#ifndef _GETADDMTROOMPOS_MAPPER_
#define _GETADDMTROOMPOS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/GetAddmtroompos/GetAddmtroomposDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class GetAddmtroomposMapper : public Mapper<GetAddmtroomposDO>
{
public:
	GetAddmtroomposDO mapper(ResultSet* resultSet) const override
	{
		GetAddmtroomposDO data;
		//data.setXcreateTime(resultSet->getString(1));
		//data.setXupdateTime(resultSet->getString(2));
		data.setXid(resultSet->getString(1));
		data.setXaddress(resultSet->getString(2));
		data.setXname(resultSet->getString(3));
		/*data.setXpinyin(resultSet->getString(5));
		data.setXpinyinInitial(resultSet->getString(6));*/
		return data;
	}
};

#endif // !_GETADDMTROOMPOS_MAPPER_