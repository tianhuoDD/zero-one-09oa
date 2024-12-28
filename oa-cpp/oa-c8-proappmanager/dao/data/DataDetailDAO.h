#pragma once
#ifndef _DATADETAIL_DAO_
#define _DATADETAIL_DAO_
#include "BaseDAO.h"
#include "domain/do/data/DataDetailDO.h"
#include "domain/do/data/DataDetailSubDO.h"
#include "domain/query/data/DataDetailQuery.h"

/**
 * 示例表数据库操作实现
 */
class DataDetailDAO : public BaseDAO
{
public:
	// 通过应用标识符和数据标识符查询数据
	list<DataDetailDO> selectByAppIdAndDataId(const string& dataid);
	list<DataDetailSubDO> selectData(const string& dataid);

};
#endif // !_SAMPLE_DAO_