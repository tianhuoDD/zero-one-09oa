#pragma once
#ifndef _ADDSERVE_
#define _ADDSERVE_
#include <list>
#include "../../domain/dto/Person/add/PersonInfoDTO.h"
#include "../../domain/do/org_personDo/org_personDO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class AddServe
{
public:

	// ��������
	uint64_t saveData(const PersioninfoDTO::Wrapper& dto);
	//ɾ������
	bool removeData(string id);
	//��ȡ��ǰʱ��
	string getTime();
	//��ȡ���к�
	string getSequence(string time, string id);
	//��ȡ����
	int getAge(string time, string birth);
};

#endif  
