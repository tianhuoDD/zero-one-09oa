#pragma once
#ifndef _DATALIST_DO_
#define _DATALIST_DO_
#include "../DoInclude.h"

/**
 * �б����ݿ�ʵ����
 */
class DataListDO
{
	
	// ����Ψһ��ʶ��
	CC_SYNTHESIZE(string, dataid, DataId);
	//Ӧ�ó���
	CC_SYNTHESIZE(string, application, Application);
	// ����������
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, alias, Alias);
	// ����
	CC_SYNTHESIZE(string, description, Description);
	//����ʱ��
	CC_SYNTHESIZE(string, creatTime, CreatTime);
	//����ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	
public:
	DataListDO() {
		dataid = "";
		application = "";
		name = "";
		alias = "";
		description = "";
		creatTime = "";
		updateTime = "";
	}
};

#endif // !_SAMPLE_DO_
