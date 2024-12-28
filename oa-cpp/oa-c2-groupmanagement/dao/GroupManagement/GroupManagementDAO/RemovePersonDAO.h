#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 26�� ������ 09:37:55 CST
*/
#ifndef _REMOVEPERSON_DAO_
#define _REMOVEPERSON_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/put/OrgGroupPersonlistDO.h"
#include "../../../domain/dto/del/RemovePersonDTO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RemovePersonDAO : public BaseDAO
{
public:
	// ͨ�����˳�Ա��ʶxpersonListɾ������
	int deleteByXgroup_Xperson(const string& group_person);
};
#endif // !_REMOVEPERSON_DAO_
