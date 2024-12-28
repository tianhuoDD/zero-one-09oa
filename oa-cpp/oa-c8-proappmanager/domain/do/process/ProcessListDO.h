#pragma once
#ifndef _PROCESSLIST_DO_
#define _PROCESSLIST_DO_
#include "../DoInclude.h"

/**
 * 流程列表数据库实体类
 */
class ProcessListDO {
	// 唯一标识
	CC_SYNTHESIZE(string, xid, Xid);
	// 流程类型
	CC_SYNTHESIZE(string, xcategory, Xcategory);
	// 流程名称
	CC_SYNTHESIZE(string, xname, Xname);
	// 流程别名
	CC_SYNTHESIZE(string, xalias, Xalias);
	// 描述
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	// 最后修改日期
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
public:
	ProcessListDO() {
		this->xid = "";
		this->xcategory = "";
		this->xname = "";
		this->xalias = "";
		this->xdescription = "";
		this->xlastUpdateTime = "";
	}
};


#endif // !_PROCESSLIST_DO_
