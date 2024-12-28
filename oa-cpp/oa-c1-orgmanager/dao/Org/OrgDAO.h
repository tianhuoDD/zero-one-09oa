#pragma once
#ifndef _ORG_DAO_
#define _ORG_DAO_
#include "BaseDAO.h"
#include "domain/do/Org/OrgDO.h"

class OrgDAO : public BaseDAO
{
public:
	//插入数据
	int insert(CreateOrgDO& coDO);
	void batchDelete(DeleteOrgDO& doDO,int& cnt);
};
#endif // !_ORG_DAO_