#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Attrib_add/Attrib_add_DO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class Attrib_add_DAO : public BaseDAO
{
public:
	//����id
	uint64_t select(const Attrib_add_DO& iObj);

	// ��������
	//uint64_t insert1(const Attrib_add_DO& iObj);
	uint64_t insert2(const Attrib_add_DO& iObj);
};
#endif // !_SAMPLE_DAO_
