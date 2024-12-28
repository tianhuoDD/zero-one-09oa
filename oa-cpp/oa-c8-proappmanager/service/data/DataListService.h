#pragma once
#ifndef _DATALIST_SERVICE_
#define _DATALIST_SERVICE_

#include <list>
#include "domain/vo/data/DataListVO.h"
#include "domain/query/data/DataListQuery.h"
#include "domain/dto/data/DataListDTO.h"

/**
 * DataList服务实现，提供基础的数据列表服务实现
 */
class DataListService
{
public:
    // 分页查询所有数据
    DataListPageDTO::Wrapper listAll(const DataListQuery::Wrapper& query);
};

#endif // !_DATALIST_SERVICE_
