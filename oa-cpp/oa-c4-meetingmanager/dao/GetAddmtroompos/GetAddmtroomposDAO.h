#pragma once

#ifndef _GETADDMTROOMPOS_DAO_
#define _GETADDMTROOMPOS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/GetAddmtroompos/GetAddmtroomposDO.h"
#include "../../domain/query/getmtroompos/GetmtroomposQuery.h"

/**
 * ʾ���ݿ����ʵ��
 */
class GetAddmtroomposDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const GetmtroomposQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GetAddmtroomposDO> selectWithPage(const GetmtroomposQuery::Wrapper& query);
	// ��������
	uint64_t insert(const GetAddmtroomposDO& iObj);
	// �޸�����
	//int update(const GetAddmtroomposDO& uObj);
};
#endif // !_GETADDMTROOMPOS_DAO_
