#pragma once

#ifndef _GETADDMTROOMPOS_SERVICE_
#define _GETADDMTROOMPOS_SERVICE_
#include <list>
#include "domain/vo/getmtroompos/GetmtroomposVO.h"
#include "domain/query/getmtroompos/GetmtroomposQuery.h"
#include "domain/dto/getmtroompos/GetmtroomposDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GetAddmtroomposService
{
public:
	// ��ҳ��ѯ��������
	GetmtroomposPageDTO::Wrapper listAll(const GetmtroomposQuery::Wrapper& query);
	// ��������
	bool insertData(const AddmtroomposDTO::Wrapper& dto);
};

#endif // !_GETADDMTROOMPOS_SERVICE_

