#pragma once
#ifndef _SortByPinYin_DO_
#define _SortByPinYin_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class SortByPinYinDO
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
	// org_unitattribute表下; 拼音; xpinyin; varchar
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	// org_unitattribute表下; 唯一编码; xunique; varchar
	CC_SYNTHESIZE(string, xunique, Xunique);
public:
	SortByPinYinDO() {
		xid = 0;
		name = "";
		shuxing = "";
		value = 0;
		miaoshu = "";
		xorderNumber = 0;
		xpinyin = "";
		xunique = "";
	}
};

#endif // !_SAMPLE_DO_
