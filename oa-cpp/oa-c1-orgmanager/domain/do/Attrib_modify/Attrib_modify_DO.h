#pragma once
#ifndef _ATTRIB_DO_
#define _ATTRIB_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class Attrib_modify_DO
{
	// Ψһ���
	CC_SYNTHESIZE(string, xid, Xid);
	// ����
	CC_SYNTHESIZE(string, xdistinguishedName_pre, XdistinguishedName_pre);
	// ����
	CC_SYNTHESIZE(string, xdistinguishedName_last, XdistinguishedName_last);
	// ֵ
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	//����
	CC_SYNTHESIZE(string, xdescription, Xdescription);
public:
	Attrib_modify_DO() {
		xid = "";
		xdistinguishedName_pre = "";
		xdistinguishedName_last = "";
		xdistributeFactor = 0;
		xdescription = "";
	}
};

#endif // !_SAMPLE_DO_
