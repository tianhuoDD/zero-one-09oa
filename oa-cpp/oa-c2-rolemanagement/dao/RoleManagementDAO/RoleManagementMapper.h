#pragma once
#ifndef _DELROLE_MAPPER_
#define _DELROLE_MAPPER_

#include"Mapper.h"


#include"../../domain/do/get/GetRoleDO.h"

//ɾ����ɫ��Ϣ
class DelRoleMapper : public Mapper<GetRoleDO>
{
public:
	GetRoleDO mapper(ResultSet* resultSet) const override
	{
		//��һ����һ�����ݿ��ѯ�Ľ������ȡ���ݣ�������Щ�������õ�data ��
		GetRoleDO data;
		data.setName(resultSet->getString(""));
		data.setKey(resultSet->getString(""));
		data.setRefer(resultSet->getString(""));

		return data;
	}
};

#endif // !_DELROLE_MAPPER_


