#pragma once
#ifndef _GETPERSONMEMBER_MAPPER_
#define _GETPERSONMEMBER_MAPPER_

#include "Mapper.h"
#include "domain/do/get/getpersonmember/GetPersonMemberDO.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/getpersonmember/GetPersonMemberDTO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class GetPersonMemberMapper : public Mapper<GetPersonMemberDO>
{
public:
	GetPersonMemberDO mapper(ResultSet* resultSet) const override
	{
		GetPersonMemberDO data;
		//data.setROLE_XID(resultSet->getString(1));
		data.setXgroupList(resultSet->getString(1));
		//data.setXorderColumn(resultSet->getUInt64(3));
		return data;
	}
};

class GetMembersMapper : public Mapper<GetPersonMemberDTO>
{
public:
	GetPersonMemberDTO mapper(ResultSet* resultSet) const override
	{
		GetPersonMemberDTO data;
		//data.setROLE_XID(resultSet->getString(1));
		data.xname = resultSet->getString(2).c_str();
		data.xdescription = resultSet->getString(1).c_str();
		data.xdistinguishedName = resultSet->getString(3).c_str();
		data.xgroupList = resultSet->getString(4).c_str();
		//data.setXorderColumn(resultSet->getUInt64(3));
		return data;
	}
};

#endif // !_GETPERSONMEMBER_MAPPER_