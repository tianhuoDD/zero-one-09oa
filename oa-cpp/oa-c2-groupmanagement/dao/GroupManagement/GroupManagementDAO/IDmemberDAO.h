#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 23�� ������ 20:45:51 CST
*/
#ifndef _IDMEMBER_DAO_
#define _IDMEMBER_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/get/IDmemberDO.h"
#include "../../../domain/query/get/IDmemberQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class IDmemberDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const IDmemberQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<IDmemberDO> selectWithPage(const IDmemberQuery::Wrapper& query);
	// ͨ��������ѯ����
	//list<OrgGroupIdentitylistDO> selectByName(const string& name);

};
#endif // !_IDMEMBER_DAO_
