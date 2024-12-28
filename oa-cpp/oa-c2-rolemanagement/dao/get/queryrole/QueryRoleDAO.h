#pragma once
#ifndef _ROLELIST_DAO_
#define _ROLELIST_DAO_
#include "BaseDAO.h"
#include "domain/do/get/queryrole/QueryRoleDO.h"
#include "domain/query/get/queryrole/QueryRoleQuery.h"

class QueryRoleDAO : public BaseDAO {
public:
	// ͳ����������
	uint64_t count(const QueryRoleQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<QueryRoleDO> selectWithPage(const QueryRoleQuery::Wrapper& query);
	// ͨ���ؼ��ֲ�ѯ����
	list<QueryRoleDO> selectByWords(const string& words);
};


#endif // !_ROLELIST_DAO_
