#pragma once

#ifndef _ORGDUTY_DO_
#define _ORGDUTY_DO_
#include "DoInclude.h"


class OrgDutyDO
{
	// 职务id
	CC_SYNTHESIZE(string, xid, Xid);
	// 职务名称
	CC_SYNTHESIZE(string, xname, Xname);
	// 职务描述
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	// 拼音
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	// 拼音首字母
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);

#if 0
	// 创建时间
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// 序列
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	// 修改时间
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	// 分布要素
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	// 标识名
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	// 排序编号
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	// 唯一标识
	CC_SYNTHESIZE(string, xunique, Xunique);
	// 单元
	CC_SYNTHESIZE(string, xunit, Xunit);
#endif
public:
	OrgDutyDO() {
		xid = "";
		xname = "";
		xdescription = "";
		xpinyin = "";
		xpinyinInitial = "";
#if 0
		xsequence = "";
		xcreateTime = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xdistinguishedName = "";
		xorderNumber = 0;
		xunique = "";
#endif
	}
};


#endif
