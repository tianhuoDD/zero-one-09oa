#pragma once
#ifndef _MEETINGDO_H
#define _MEETINGDO_H
#include "../DoInclude.h"


class meetingDO
{
	//����Id
	CC_SYNTHESIZE(string, meetingId, MeetingId);

	//������
	CC_SYNTHESIZE(string, applicant, Applicant);

	//��������
	CC_SYNTHESIZE(string, type, _Type);

	//��ʼʱ��
	CC_SYNTHESIZE(string, startTime, StartTime);
	//����ʱ��
	CC_SYNTHESIZE(string, completedTime, CompletedTime);

	//������ID
	CC_SYNTHESIZE(string, room, Room);

	//������
	CC_SYNTHESIZE(string, hostPerson, HostPerson);

	//������Ա��ǩ����Ա���б����ڸ��ֶ��ж���

	//�������
	CC_SYNTHESIZE(string, subject, Subject);

	//��������
	CC_SYNTHESIZE(string, summary, Summary);

	//�а첿��
	CC_SYNTHESIZE(string, hostUnit, HostUnit);
	//ƴ��
	CC_SYNTHESIZE(string, pinyin, Pinyin);
	//ƴ������ĸ
	CC_SYNTHESIZE(string, pinyinInitial, PinyinInitial);
public:
	meetingDO() :pinyin(""), pinyinInitial(""), applicant(""), type(""), startTime(""), completedTime(""), room(""), hostPerson(""), subject(""), summary(""), hostUnit(""), meetingId("") {}
};

#endif