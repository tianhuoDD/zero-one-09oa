#pragma once
#ifndef _DATALIST_DO_
#define _DATALIST_DO_
#include "../DoInclude.h"

/**
 * �б����ݿ�ʵ����
 */
class DataDetailDO
{
	// ����Ψһ��ʶ��
	CC_SYNTHESIZE(string, data, Data);
	// ����Ψһ��ʶ��
	CC_SYNTHESIZE(string, dataid, DataId);
	// Ӧ��Ψһ��ʶ��
	CC_SYNTHESIZE(string, appid, AppId);
	//Ӧ�ó���
	CC_SYNTHESIZE(string, application, Application);
	// ����������
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, alias, Alias);
	// ����
	CC_SYNTHESIZE(string, description, Description);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//����ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);

public:
	DataDetailDO() {
		data = "";
		dataid = "";
		appid = "";
		application = "";
		name = "";
		alias = "";
		description = "";
		createTime = "";
		updateTime = "";
	}
};

#endif // !_SAMPLE_DO_
