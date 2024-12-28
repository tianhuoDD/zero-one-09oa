#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 25�� ������ 19:40:34 CST
*/
#ifndef _ADDPERSON_DAO_
#define _ADDPERSON_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/put/OrgGroupPersonlistDO.h"
#include "domain/vo/put/AddPersonVO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class AddPersonDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const OrgGroupPersonlistDO& iObj);
};
#endif // !_ADDPERSON_DAO_
