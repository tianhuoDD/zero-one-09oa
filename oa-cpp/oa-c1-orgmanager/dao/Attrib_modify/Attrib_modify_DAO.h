#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Attrib_modify/Attrib_modify_DO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class Attrib_modify_DAO : public BaseDAO
{
public:
	//����id
	uint64_t select(const Attrib_modify_DO& iObj);

	// �޸�����
	int update(const Attrib_modify_DO& uObj);
};
#endif // !_SAMPLE_DAO_
