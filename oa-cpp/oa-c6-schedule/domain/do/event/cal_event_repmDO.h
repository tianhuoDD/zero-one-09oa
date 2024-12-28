#pragma once


#ifndef _CAL_EVENT_REPM_DO_
#define _CAL_EVENT_REPM_DO_
#include "../../GlobalInclude.h"

/**
 * �ظ��ճ���Ϣʵ����
 */
class cal_event_repmDO
{
	// �ظ��ճ�id
	CC_SYNTHESIZE(string, xid, xId);
	// ����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, xCreateTime);
	// �ճ�����
	CC_SYNTHESIZE(string, xsequence, xSequence);
	// ����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, xUpdateTime);
	//�ֲ�����
	CC_SYNTHESIZE(int, xdistributeFactor, xDistributeFactor);
	//�Ƿ�����
	CC_SYNTHESIZE(int, xalarm, xAlarm);
	//����ʱ��
	CC_SYNTHESIZE(string, xalarmTime, xAlarmTime);
	//����id
	CC_SYNTHESIZE(string, xcalendarId, xCalendarId);
	//��ɫ
	CC_SYNTHESIZE(string, xcolor, xColor);
	//����
	CC_SYNTHESIZE(string, xcomment, xComment);
	//���ݱ�id
	CC_SYNTHESIZE(string, xcommentId, xCommentId);
	//������
	CC_SYNTHESIZE(string, xcreatePerson, xCreatePerson);
	//
	CC_SYNTHESIZE(int, xdaysOfDuration, xDaysOfDuration);
	//����ʱ��
	CC_SYNTHESIZE(string, xendTime, xEndTime);
	//�¼�����
	CC_SYNTHESIZE(string, xeventType, xEventType);
	//�Ƿ�ȫ��
	CC_SYNTHESIZE(int, xisAllDayEvent, xIsAllDayEvent);
	//�Ƿ񹫿�
	CC_SYNTHESIZE(int, xisPublic, xIsPublic);
	//
	CC_SYNTHESIZE(string, xlatitude, xLatitude);
	//�ص�
	CC_SYNTHESIZE(string, xlocationName, xLocationName);
	//
	CC_SYNTHESIZE(string, xlongitude, xLongitude);
	//
	CC_SYNTHESIZE(string, xrecurrenceExc, xRecurrenceExc);
	//�ظ���ʽ
	CC_SYNTHESIZE(string, xrecurrenceRule, xRecurrenceRule);
	//�ظ���ʼʱ��
	CC_SYNTHESIZE(string, xrecurrenceStartTime, xRecurrenceStartTime);
	//�ظ�״̬
	CC_SYNTHESIZE(string, xrepeatStatus, xRepeatStatus);
	//
	CC_SYNTHESIZE(string, xsource, xSource);
	//�ճ̿�ʼʱ��
	CC_SYNTHESIZE(string, xstartTime, xStartTime);
	//�ճ�Ŀ������
	CC_SYNTHESIZE(string, xtargetType, xTargetType);
	//����
	CC_SYNTHESIZE(string, xtitle, xTitle);
	//������
	CC_SYNTHESIZE(string, xupdatePerson, xUpdatePerson);
	//���ѷ�ʽ
	CC_SYNTHESIZE(string, xvalarmTime_config, xValarmTime_config);
	//�ܽ�
	CC_SYNTHESIZE(string, xvalarm_Summary, xValarm_Summary);
	//
	CC_SYNTHESIZE(string, xvalarm_description, xValarm_description);
	//
	CC_SYNTHESIZE(string, xvalarm_mailto, xValarm_mailto);



public:
	cal_event_repmDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = NULL;
		xalarm = 0;
		xalarmTime = "";
		xcalendarId = "";
		xcolor = "";
		xcomment = "";
		xcommentId = "";
		xcreatePerson = "";
		xdaysOfDuration = 0;
		xendTime = "";
		xeventType = "";
		xisAllDayEvent = 0;
		xisPublic = 0;
		xlatitude = "";
		xlocationName = "";
		xlongitude = "";
		xrecurrenceExc = "";
		xrecurrenceRule = "";
		xrecurrenceStartTime = "";
		xrepeatStatus = "";
		xsource = "";
		xstartTime = "";
		xtargetType = "";
		xtitle = "";
		xupdatePerson = "";
		xvalarmTime_config = "";
		xvalarm_Summary = "";
		xvalarm_description = "";
		xvalarm_mailto = "";


	}
};

#endif // !_CAL_EVENT_REPM_DO_