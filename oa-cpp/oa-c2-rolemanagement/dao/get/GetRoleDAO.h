#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/get/GetRoleDO.h"
#include "../../domain/query/GetRole/GetRoleMemberQuery.h"
class GetRoleDAO : public BaseDAO
{
public:



		// ͨ��������ѯ����
	//list<GetRoleDO> selectByName(const string& name);
	// ͨ��id��ѯ����
	list<GetRoleDO> selectById(const string& id);

};
#endif // !_SAMPLE_DAO_

