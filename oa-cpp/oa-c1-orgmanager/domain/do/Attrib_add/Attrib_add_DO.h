#pragma once
#ifndef _ATTRIB_DO_
#define _ATTRIB_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class Attrib_add_DO
{
	// Ψһ���
	CC_SYNTHESIZE(string, xid, Xid);
	// ����
	CC_SYNTHESIZE(string, xname, Xname);
	// ����
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	// ֵ
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	//����
	CC_SYNTHESIZE(string, xdescription, Xdescription);
public:
	Attrib_add_DO() {
		xid = "";
		xname = "";
		xdistinguishedName = "";
		xdistributeFactor = 0;
		xdescription = "";
	}
};

#endif // !_SAMPLE_DO_
