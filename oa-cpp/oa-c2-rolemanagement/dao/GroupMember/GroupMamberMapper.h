#pragma once
#ifndef _GROUPMEMBER_MAPPER_
#define _GROUPMEMBER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/GroupMember/GroupMemberDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class GroupMemberMapper : public Mapper<GroupMemberDO>
{
public:
	GroupMemberDO mapper(ResultSet* resultSet) const override
	{
		GroupMemberDO data;
		data.setGroupname(resultSet->getString(1));
		data.setGroupnameA(resultSet->getString(2));
		data.setGroupdes(resultSet->getString(3));
		return data;
	}
};

#endif // !_GROUPMEMBER_MAPPER_