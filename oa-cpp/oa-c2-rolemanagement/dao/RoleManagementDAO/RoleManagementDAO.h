#pragma once
#ifndef _DELROLE_DAO_
#define _DELROLE_DAO_
#include"BaseDAO.h"
#include "domain/dto/get/GetroleDTO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class DelRoleDAO : public BaseDAO
{
public:

	// ͨ��IDɾ������
	int deleteById(string id);
};

#endif // !_DELROLE_DAO_
