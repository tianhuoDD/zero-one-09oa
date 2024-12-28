#pragma once

#ifndef _ORGGROUPDO_H_
#define _ORGGROUPDO_H_


#include "../DoInclude.h"


class OrgGroupDO
{
	//// ����
		//CC_SYNTHESIZE(string, name, Name);
		//// ���
		//CC_SYNTHESIZE(string, id, Id);
		//// ����
		//CC_SYNTHESIZE(string, description, Description);

	// ���
	CC_SYNTHESIZE(string, xid, xId);
	//����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, xCreateTime);
	//����
	CC_SYNTHESIZE(string, xsequence, xSequence);
	//����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, xUpdateTime);
	//��������
	CC_SYNTHESIZE(int, xdistributeFactor, xDistributeFactor);
	// ����
	CC_SYNTHESIZE(string, xdescription, xDescription);
	//������
	CC_SYNTHESIZE(string, xdistinguishedName, xDistinguishedName);
	// ����
	CC_SYNTHESIZE(string, xname, xName);
	//����
	CC_SYNTHESIZE(int, xorderNumber, xOrderNumber);
	//ƴ��
	CC_SYNTHESIZE(string, xpinyin, xPinyin);
	//��ʼ��ƴ��
	CC_SYNTHESIZE(string, xpinyinInitial, xPinyinInitial);
	//Ψһ
	CC_SYNTHESIZE(string, xunique, xUnique);
public:
	OrgGroupDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = -1;
		xdescription = "";
		xdistinguishedName = "";
		xname = "";
		xorderNumber = -1;
		xpinyin = "";
		xpinyinInitial = "";
		xunique = "";
	}
};

#endif // !_ORGGROUPDO_H_