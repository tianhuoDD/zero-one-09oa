#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 23�� ������ 17:36:17 CST
*/
#ifndef _IDMEMBERQUERY_SERVICE_
#define _IDMEMBERQUERY_SERVICE_
#include <list>
#include "domain/vo/get/IDmemberVO.h"
#include "domain/query/get/IDmemberQuery.h"
#include "domain/dto/get/IDmemberDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class IDmemberQueryService
{
public:
	// ��ҳ��ѯ��������
	IDmemberPageDTO::Wrapper listAll(const IDmemberQuery::Wrapper& query);
};

#endif // !_IDMEMBERQUERY_SERVICE_

