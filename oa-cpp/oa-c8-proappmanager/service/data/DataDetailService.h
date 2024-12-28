#pragma once
#ifndef _DATADETAIL_SERVICE_
#define _DATADETAIL_SERVICE_

#include <list>
#include "domain/vo/data/DataDetailVO.h"
#include "domain/query/data/DataDetailQuery.h"
#include "domain/dto/data/DataDetailDTO.h"

/**
 * DataDetail服务实现，提供基础的数据详情服务实现
 */
class DataDetailService
{
public:
    // 查询详情数据
    DataDetailDTO::Wrapper listOne(const std::string& dataid);
};

#endif // !_DATADETAIL_SERVICE_
