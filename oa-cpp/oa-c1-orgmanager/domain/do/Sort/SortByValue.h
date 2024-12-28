#pragma once
#ifndef _SortByValue_DO_
#define _SortByValue_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class SortByValueDO
{
	// Ψһ���
	CC_SYNTHESIZE(uint64_t, xid, Xid);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, shuxing, Shuxing);
	// ֵ
	CC_SYNTHESIZE(int, value, Value);
	//����
	CC_SYNTHESIZE(string, miaoshu, Miaoshu);
	// org_unitattribute����; �����; xorderNumber; int
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	// org_unitattribute����; Ψһ����; xunique; varchar
	CC_SYNTHESIZE(string, xunique, Xunique);
public:
	SortByValueDO() {
		xid = 0;
		name = "";
		shuxing = "";
		value = 0;
		miaoshu = "";
		xorderNumber = 0;
		xunique = "";
	}
};

#endif // !_SAMPLE_DO_
