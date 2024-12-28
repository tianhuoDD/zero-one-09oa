#pragma once
#ifndef _CURRENTLIST_H_
#define _CURRENTLIST_H_

#include "../DoInclude.h"

class CurrentListDO
{
	//关联的会议id
	CC_SYNTHESIZE(string, meetingId, MeetingId);
	//相关的人员或组织
	CC_SYNTHESIZE(string, xlist, Xlist);
	//操纵行
	CC_SYNTHESIZE(int, orderColumn, OrderColumn);
public:
	CurrentListDO() :meetingId(""), xlist(""), orderColumn(0) {}

};

#endif // !_CURRENTLIST_H_
