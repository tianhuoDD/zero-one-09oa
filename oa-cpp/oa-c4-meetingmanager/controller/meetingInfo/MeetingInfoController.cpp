#include"MeetingInfoController.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>


MeetInfoJsonVO::Wrapper MeetingInfoController::execQueryDetailMeetingInfo(const String& Id, const PayloadDTO& payload)
{
	MeetingService meetingService;
	auto res = meetingService.queryMeetingInfoById(Id);
	auto jvo = MeetInfoJsonVO::createShared();
	jvo->success(res);
	return jvo;
}
StringJsonVO::Wrapper MeetingInfoController::execModifyMeetingInfo(const MeetingInfo::Wrapper& meeting, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	//参数校验
	//id的格式是8+4+4+12  xxxxxxxx-xxxx-xxxx-xxxxxxxxxxxx
	//时间校验是否合法
	string beginTime = meeting->startTime.getValue("");
	string completedTime = meeting->completedTime.getValue("");
	if (strcmp(beginTime.c_str(), completedTime.c_str()) >= 0) {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.startTimeGreaterCompletedTime")), RS_PARAMS_INVALID);
		return jvo;
	}
	//校验会议标题是否非空
	if (meeting->subject->empty()) {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.emptySubject")), RS_PARAMS_INVALID);
		return jvo;
	}
	//校验参会人员是否为空
	if (meeting->inviteMemberList->empty()) {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.emptyMemberList")), RS_PARAMS_INVALID);
		return jvo;
	}
	//校验主持人和承办部门是否为空
	if (meeting->hostUnit.getValue("") == "") {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.emptyHostUnit")), RS_PARAMS_INVALID);
		return jvo;
	}
	if (meeting->hostPerson.getValue("") == "") {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.emptyHostPerson")), RS_PARAMS_INVALID);
		return jvo;
	}
	//呼叫service层
	MeetingService service;


	if (service.modifyMeetingInfo(meeting)) {
		jvo->success(meeting->meetingId);
	}
	else {
		jvo->fail(meeting->meetingId);
	}
	return jvo;
}