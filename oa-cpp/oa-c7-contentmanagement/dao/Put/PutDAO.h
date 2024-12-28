#pragma once
#pragma once
#ifndef _PUTDAO_
#define _PUTDAO_
#include "BaseDAO.h"
#include "../../domain/do/New/PutDO.h"
/**
 * 示例表数据库操作实现
 */
class PutDAO : public BaseDAO
{
public:
	// 通过分类标识查询数据
	
	// 修改数据
	int update(const PutDO& uObj);
	// 通过ID删除数据
	
};
#endif // !_SAMPLE_DAO_
