#pragma once
#ifndef _ATTRIB_DO_
#define _ATTRIB_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class Attrib_modify_DO
{
	// 唯一编号
	CC_SYNTHESIZE(string, xid, Xid);
	// 属性
	CC_SYNTHESIZE(string, xdistinguishedName_pre, XdistinguishedName_pre);
	// 属性
	CC_SYNTHESIZE(string, xdistinguishedName_last, XdistinguishedName_last);
	// 值
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	//描述
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
