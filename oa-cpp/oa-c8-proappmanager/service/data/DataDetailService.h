#pragma once
#ifndef _DATADETAIL_SERVICE_
#define _DATADETAIL_SERVICE_

#include <list>
#include "domain/vo/data/DataDetailVO.h"
#include "domain/query/data/DataDetailQuery.h"
#include "domain/dto/data/DataDetailDTO.h"

/**
 * DataDetail����ʵ�֣��ṩ�����������������ʵ��
 */
class DataDetailService
{
public:
    // ��ѯ��������
    DataDetailDTO::Wrapper listOne(const std::string& dataid);
};

#endif // !_DATADETAIL_SERVICE_
