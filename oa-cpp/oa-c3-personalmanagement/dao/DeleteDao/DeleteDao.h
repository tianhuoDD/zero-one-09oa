#pragma once
#ifndef _DELETEDAO_
#define _DELETEDAO_
#include"../../domain/do/org_personDo/org_personDO.h"
#include "BaseDAO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DeleteDao : public BaseDAO
{
public:
	 
	// ͨ��IDɾ������
	int deleteById(string id);
 
};
#endif  