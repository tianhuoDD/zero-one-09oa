#pragma once
#ifndef _MEETINGDO_H
#define _MEETINGDO_H
#include "../DoInclude.h"


class meetingDO
{
	//会议Id
	CC_SYNTHESIZE(string, meetingId, MeetingId);

	//申请人
	CC_SYNTHESIZE(string, applicant, Applicant);

	//会议类型
	CC_SYNTHESIZE(string, type, _Type);

	//开始时间
	CC_SYNTHESIZE(string, startTime, StartTime);
	//结束时间
	CC_SYNTHESIZE(string, completedTime, CompletedTime);

	//会议室ID
	CC_SYNTHESIZE(string, room, Room);

	//主持人
	CC_SYNTHESIZE(string, hostPerson, HostPerson);

	//接受人员，签到人员的列表不能在该字段中定义

	//会议标题
	CC_SYNTHESIZE(string, subject, Subject);

	//会议描述
	CC_SYNTHESIZE(string, summary, Summary);

	//承办部门
	CC_SYNTHESIZE(string, hostUnit, HostUnit);
	//拼音
	CC_SYNTHESIZE(string, pinyin, Pinyin);
	//拼音首字母
	CC_SYNTHESIZE(string, pinyinInitial, PinyinInitial);
public:
	meetingDO() :pinyin(""), pinyinInitial(""), applicant(""), type(""), startTime(""), completedTime(""), room(""), hostPerson(""), subject(""), summary(""), hostUnit(""), meetingId("") {}
};

#endif