#pragma once
#pragma once
#ifndef _PUTDAO_
#define _PUTDAO_
#include "BaseDAO.h"
#include "../../domain/do/New/PutDO.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class PutDAO : public BaseDAO
{
public:
	// ͨ�������ʶ��ѯ����
	
	// �޸�����
	int update(const PutDO& uObj);
	// ͨ��IDɾ������
	
};
#endif // !_SAMPLE_DAO_
