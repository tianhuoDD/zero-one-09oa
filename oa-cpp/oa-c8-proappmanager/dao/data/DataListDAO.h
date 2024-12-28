#pragma once
#ifndef _DATAList_DAO_
#define _DATAList_DAO_
#include "BaseDAO.h"
#include "domain/do/data/DataListDO.h"
#include "domain/query/data/DataListQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DataListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const DataListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<DataListDO> selectWithPage(const DataListQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_