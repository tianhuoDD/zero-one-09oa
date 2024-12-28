#pragma once
#ifndef _DATALIST_SERVICE_
#define _DATALIST_SERVICE_

#include <list>
#include "domain/vo/data/DataListVO.h"
#include "domain/query/data/DataListQuery.h"
#include "domain/dto/data/DataListDTO.h"

/**
 * DataList����ʵ�֣��ṩ�����������б����ʵ��
 */
class DataListService
{
public:
    // ��ҳ��ѯ��������
    DataListPageDTO::Wrapper listAll(const DataListQuery::Wrapper& query);
};

#endif // !_DATALIST_SERVICE_
