#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 25�� ������ 19:33:03 CST
*/
#ifndef _ADDPERSON_SERVICE_
#define _ADDPERSON_SERVICE_
#include <list>
#include "domain/vo/put/AddPersonVO.h"
#include "domain/dto/put/AddPersonDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class AddPersonService
{
public:
	// ��������
	AddPersonDTO::Wrapper saveData(const AddPersonDTO::Wrapper& dto);
};

#endif // !_ADDPERSON_SERVICE_

