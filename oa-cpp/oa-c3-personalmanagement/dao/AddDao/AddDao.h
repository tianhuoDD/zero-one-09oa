#pragma once
#ifndef _ADDDAO_
#define _ADDDAO_
#include"../../domain/do/org_personDo/org_personDO.h"
#include "BaseDAO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class AddDao : public BaseDAO
{
public:
	 
	// ��������
	uint64_t insert(const org_personDO& iObj);
 
};
#endif  