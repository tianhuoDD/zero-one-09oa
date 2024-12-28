#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Attrib_modify/Attrib_modify_DO.h"

/**
 * 示例表数据库操作实现
 */
class Attrib_modify_DAO : public BaseDAO
{
public:
	//查找id
	uint64_t select(const Attrib_modify_DO& iObj);

	// 修改数据
	int update(const Attrib_modify_DO& uObj);
};
#endif // !_SAMPLE_DAO_
