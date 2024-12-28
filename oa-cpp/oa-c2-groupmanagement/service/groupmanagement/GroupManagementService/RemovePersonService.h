#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 26�� ������ 09:37:55 CST
*/
#ifndef _REMOVEPERSON_SERVICE_
#define _REMOVEPERSON_SERVICE_
#include <list>
#include "domain/vo/del/RemovePersonVO.h"
#include "domain/dto/del/RemovePersonDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RemovePersonService
{
public:
	// ͨ��xpersonListɾ������
	bool removeData(const string&group_person);
};

#endif // !_REMOVEPERSON_SERVICE_

