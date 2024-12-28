#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Attrib_add/Attrib_add_DO.h"

/**
 * 示例表数据库操作实现
 */
class Attrib_add_DAO : public BaseDAO
{
public:
	//查找id
	uint64_t select(const Attrib_add_DO& iObj);

	// 插入数据
	//uint64_t insert1(const Attrib_add_DO& iObj);
	uint64_t insert2(const Attrib_add_DO& iObj);
};
#endif // !_SAMPLE_DAO_
