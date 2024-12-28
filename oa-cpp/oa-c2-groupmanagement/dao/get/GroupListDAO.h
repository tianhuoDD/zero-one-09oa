#pragma once

#ifndef _GROUPLIST_DAO_
#define _GROUPLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/get/GroupListDO.h"
#include "../../domain/query/get/GroupListQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class GroupListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const GroupListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GroupListDO> selectWithPage(const GroupListQuery::Wrapper& query);
	// ��������
	uint64_t insert(const GroupListDO& iObj);
};
#endif // !_SAMPLE_DAO_
