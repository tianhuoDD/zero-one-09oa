#pragma once
#ifndef _PUTSERVICE_
#define _PUTSERVICE_
#include <list>
#include"domain/vo/New/PutVO.h"
#include"domain/dto/New/PutDTO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PutService
{
public:
	//��ѯ����
	
	bool updateData(const PutDTO::Wrapper& dto);
	// ͨ�����ʶɾ������
	
};

#endif // 

