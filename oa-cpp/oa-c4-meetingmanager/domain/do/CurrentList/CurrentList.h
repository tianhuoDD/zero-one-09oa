#pragma once
#ifndef _CURRENTLIST_H_
#define _CURRENTLIST_H_

#include "../DoInclude.h"

class CurrentListDO
{
	//�����Ļ���id
	CC_SYNTHESIZE(string, meetingId, MeetingId);
	//��ص���Ա����֯
	CC_SYNTHESIZE(string, xlist, Xlist);
	//������
	CC_SYNTHESIZE(int, orderColumn, OrderColumn);
public:
	CurrentListDO() :meetingId(""), xlist(""), orderColumn(0) {}

};

#endif // !_CURRENTLIST_H_
