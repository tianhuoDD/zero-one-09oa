#pragma once
#ifndef _DATADETAIL_DAO_
#define _DATADETAIL_DAO_
#include "BaseDAO.h"
#include "domain/do/data/DataDetailDO.h"
#include "domain/do/data/DataDetailSubDO.h"
#include "domain/query/data/DataDetailQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DataDetailDAO : public BaseDAO
{
public:
	// ͨ��Ӧ�ñ�ʶ�������ݱ�ʶ����ѯ����
	list<DataDetailDO> selectByAppIdAndDataId(const string& dataid);
	list<DataDetailSubDO> selectData(const string& dataid);

};
#endif // !_SAMPLE_DAO_