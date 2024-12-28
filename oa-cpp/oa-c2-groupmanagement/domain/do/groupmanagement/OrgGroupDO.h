#pragma once

#ifndef _ORGGROUPDO_H_
#define _ORGGROUPDO_H_


#include "../DoInclude.h"


class OrgGroupDO
{
	//// 姓名
		//CC_SYNTHESIZE(string, name, Name);
		//// 编号
		//CC_SYNTHESIZE(string, id, Id);
		//// 描述
		//CC_SYNTHESIZE(string, description, Description);

	// 编号
	CC_SYNTHESIZE(string, xid, xId);
	//创建时间
	CC_SYNTHESIZE(string, xcreateTime, xCreateTime);
	//序列
	CC_SYNTHESIZE(string, xsequence, xSequence);
	//更新时间
	CC_SYNTHESIZE(string, xupdateTime, xUpdateTime);
	//分配因素
	CC_SYNTHESIZE(int, xdistributeFactor, xDistributeFactor);
	// 描述
	CC_SYNTHESIZE(string, xdescription, xDescription);
	//分配名
	CC_SYNTHESIZE(string, xdistinguishedName, xDistinguishedName);
	// 姓名
	CC_SYNTHESIZE(string, xname, xName);
	//排名
	CC_SYNTHESIZE(int, xorderNumber, xOrderNumber);
	//拼音
	CC_SYNTHESIZE(string, xpinyin, xPinyin);
	//初始化拼音
	CC_SYNTHESIZE(string, xpinyinInitial, xPinyinInitial);
	//唯一
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