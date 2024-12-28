#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Sort/SortByPinYinDO.h"
#include "../../domain/query/Sort/SortByPinYinQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SortByPinYinDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const SortByPinYinQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<SortByPinYinDO> selectWithPage(const SortByPinYinQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<SortByPinYinDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const SortByPinYinDO& iObj);
	// �޸�����
	int update(const SortByPinYinDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
