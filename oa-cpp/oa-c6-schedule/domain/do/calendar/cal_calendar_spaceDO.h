#pragma once
#ifndef _CAL_CALENDAR_SPACEDO_H_
#define _CAL_CALENDAR_SPACEDO_H_
#include "../DoInclude.h"
#include "cal_calendarDO.h"

/**
 * ���ݿ�ʵ�嵫����ôʵ�����
 */
class cal_calendar_spaceDO
{
	// ���
	CC_SYNTHESIZE(string, xid, Xid);
	// ����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// ��ɫ
	CC_SYNTHESIZE(string, xcolor, Xcolor);
	// �½�
	CC_SYNTHESIZE(string, xcreateor, Xcreateor);
	// ��������
	CC_SYNTHESIZE(string, xname, Xname);
	// ����
	CC_SYNTHESIZE(string, xtype, Xtype);
	// ��ע
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	// �Ƿ��ע
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
