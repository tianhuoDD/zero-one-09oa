#pragma once
#ifndef _PROCESSLIST_DO_
#define _PROCESSLIST_DO_
#include "../DoInclude.h"

/**
 * �����б����ݿ�ʵ����
 */
class ProcessListDO {
	// Ψһ��ʶ
	CC_SYNTHESIZE(string, xid, Xid);
	// ��������
	CC_SYNTHESIZE(string, xcategory, Xcategory);
	// ��������
	CC_SYNTHESIZE(string, xname, Xname);
	// ���̱���
	CC_SYNTHESIZE(string, xalias, Xalias);
	// ����
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	// ����޸�����
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
public:
	ProcessListDO() {
		this->xid = "";
		this->xcategory = "";
		this->xname = "";
		this->xalias = "";
		this->xdescription = "";
		this->xlastUpdateTime = "";
	}
};


#endif // !_PROCESSLIST_DO_
