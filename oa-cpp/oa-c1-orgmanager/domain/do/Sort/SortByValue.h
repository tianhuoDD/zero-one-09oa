#pragma once
#ifndef _SortByValue_DO_
#define _SortByValue_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class SortByValueDO
{
	// 唯一编号
	CC_SYNTHESIZE(uint64_t, xid, Xid);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 属性
	CC_SYNTHESIZE(string, shuxing, Shuxing);
	// 值
	CC_SYNTHESIZE(int, value, Value);
	//描述
	CC_SYNTHESIZE(string, miaoshu, Miaoshu);
	// org_unitattribute表下; 排序号; xorderNumber; int
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	// org_unitattribute表下; 唯一编码; xunique; varchar
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
