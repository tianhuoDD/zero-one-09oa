#pragma once

#ifndef _GETADDMTROOMPOS_DO_
#define _GETADDMTROOMPOS_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class GetAddmtroomposDO
{
	// 会议室位置	
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(string, xaddress, Xaddress);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);

public:
	GetAddmtroomposDO() {
		xid = "";
		xcreateTime = "";
		xupdateTime = "";
		xaddress = "";
		xname = "";
		xpinyin = "";
		xpinyinInitial = "";
	}
};

#endif // !_GETADDMTROOMPOS_DO_
