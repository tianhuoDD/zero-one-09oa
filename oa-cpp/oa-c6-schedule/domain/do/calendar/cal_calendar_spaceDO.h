#pragma once
#ifndef _CAL_CALENDAR_SPACEDO_H_
#define _CAL_CALENDAR_SPACEDO_H_
#include "../DoInclude.h"
#include "cal_calendarDO.h"

/**
 * 数据库实体但不那么实体的类
 */
class cal_calendar_spaceDO
{
	// 编号
	CC_SYNTHESIZE(string, xid, Xid);
	// 创建时间
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// 颜色
	CC_SYNTHESIZE(string, xcolor, Xcolor);
	// 新建
	CC_SYNTHESIZE(string, xcreateor, Xcreateor);
	// 日历名称
	CC_SYNTHESIZE(string, xname, Xname);
	// 类型
	CC_SYNTHESIZE(string, xtype, Xtype);
	// 备注
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	// 是否关注
	CC_SYNTHESIZE(string, xisfollow, Xisfollow);
public:
	cal_calendar_spaceDO() {
		xid = "12314564";
		xcreateTime = "2024-10-23";
		xcolor = "#428ffc";
		xcreateor = "xadmin";
		xname = "1";
		xtype = "PERSON";
		xdescription = "";
		xisfollow = "false";
	}
};

#endif // !_CAL_CALENDAR_SPACEDO_H_
