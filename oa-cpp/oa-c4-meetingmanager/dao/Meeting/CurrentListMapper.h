#pragma once
#ifndef _CURRENTLIST_MAPPER_H_
#define _CURRENTLIST_MAPPER_H_
#include"Mapper.h"
#include"domain/do/CurrentList/CurrentList.h"
class CurrentListMapper : public Mapper<CurrentListDO>
{
public:
	CurrentListDO mapper(ResultSet* resultSet) const override
	{
		CurrentListDO currentListDO;
		currentListDO.setMeetingId(resultSet->getString(1));
		currentListDO.setXlist(resultSet->getString(2));
		currentListDO.setOrderColumn(resultSet->getInt(3));
		return currentListDO;
	}
};





#endif // !

