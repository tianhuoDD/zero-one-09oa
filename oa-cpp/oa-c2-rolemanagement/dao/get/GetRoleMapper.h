#pragma once
#pragma once
#ifndef _DETROLE_MAPPER_
#define _DETROLE_MAPPER_

#include"Mapper.h"

#include "../../domain/do/get/GetRoleDO.h"

//��ȡ��ɫ��Ϣ
class GetRoleMapper : public Mapper<GetRoleDO>
{
public:
	GetRoleDO mapper(ResultSet* resultSet) const override
	{
		//��һ����һ�����ݿ��ѯ�Ľ������ȡ���ݣ�������Щ�������õ�data ��
		GetRoleDO data;
		data.setName(resultSet->getString("xname"));
		data.setKey(resultSet->getString("xunique"));
		data.setRefer(resultSet->getString("xdescription"));
		data.setFullname(resultSet->getString("xdistinguishedName"));
		data.setStartTime(resultSet->getString("xcreateTime"));
		data.setEndTime(resultSet->getString("xupdateTime"));
		


		return data;
	}
};

#endif // !_DETROLE_MAPPER_