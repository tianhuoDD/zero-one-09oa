#pragma once
#ifndef _ATTRIB_DO_
#define _ATTRIB_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class Attrib_add_DO
{
	// 唯一编号
	CC_SYNTHESIZE(string, xid, Xid);
	// 名称
	CC_SYNTHESIZE(string, xname, Xname);
	// 属性
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	// 值
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	//描述
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
