
#pragma once
#ifndef _GETROLE_DO_
#define _GETROLE_DO_
#include"../DoInclude.h"
#include"../../GlobalInclude.h"


class GetRoleDO
{
	//�����������ڶ���������ʵ�ʵ����Ա�����������ڴ洢�����Ψһ��ʶ�����ڲ�ʹ��
	// �����������Ե����ƣ�ͨ���������ɷ��������޸������ⲿʹ��

	//��ɫ����
	CC_SYNTHESIZE(string, name, Name);
	// ?��??����??
	CC_SYNTHESIZE(string, key, Key);
	// ?????��??
	CC_SYNTHESIZE(string, refer, Refer);
	//��ȡ��ɫȫ��
	CC_SYNTHESIZE(string, fullname, Fullname);
	//����ʱ��
	CC_SYNTHESIZE(string, startTime, StartTime);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, endTime, EndTime);


public:
	GetRoleDO() {
		name = "";
		key = "";
		refer = "";
		fullname = "";
		startTime = "";
		endTime = "";


	}

};


#endif // !_GETROLE_DO_
