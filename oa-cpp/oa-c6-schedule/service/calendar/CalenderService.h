#pragma once
#ifndef _CALENDER_SERVICE_
#define _CALENDER_SERVICE_
#include <list>
#include "../../domain/vo/calender/CalenderInfoVO.h"
#include "../../domain/dto/calender/CalenderInfoDTO.h"


class CalenderDAO;

class CalenderService
{
private:
	//�жϷָ��Ƿ�ȫ���ɹ�  -1Ϊ�������������� 
	int divisionsuccess = 999;
	// �ָ�����
	list<string> division(string waitDivision);
	//��Ͽɼ���Χ�����½���Χ����
	uint64_t packaging(const CalenderInfoDTO::Wrapper& dto, CalenderDAO& dao, const string& loaddisName, const string& xid);

public:
	// ��������
	uint64_t saveData(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName);
	// �޸�����
	uint64_t updateData(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName);
	// ͨ��IDɾ������
	bool removeData(string xid);

};

#endif // !_CALENDER_SERVICE_