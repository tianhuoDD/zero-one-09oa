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
	//����У��
	//id�ĸ�ʽ��8+4+4+12  xxxxxxxx-xxxx-xxxx-xxxxxxxxxxxx
	//ʱ��У���Ƿ�Ϸ�
	string beginTime = meeting->startTime.getValue("");
	string completedTime = meeting->completedTime.getValue("");
	if (strcmp(beginTime.c_str(), completedTime.c_str()) >= 0) {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.startTimeGreaterCompletedTime")), RS_PARAMS_INVALID);
		return jvo;
	}
	//У���������Ƿ�ǿ�
	if (meeting->subject->empty()) {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.emptySubject")), RS_PARAMS_INVALID);
		return jvo;
	}
	//У��λ���Ա�Ƿ�Ϊ��
	if (meeting->inviteMemberList->empty()) {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.emptyMemberList")), RS_PARAMS_INVALID);
		return jvo;
	}
	//У�������˺ͳа첿���Ƿ�Ϊ��
	if (meeting->hostUnit.getValue("") == "") {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.emptyHostUnit")), RS_PARAMS_INVALID);
		return jvo;
	}
	if (meeting->hostPerson.getValue("") == "") {
		jvo->init(String(ZH_WORDS_GETTER("meeting-manager.resultStatus.emptyHostPerson")), RS_PARAMS_INVALID);
		return jvo;
	}
	//����service��
	MeetingService service;


	if (service.modifyMeetingInfo(meeting)) {
		jvo->success(meeting->meetingId);
	}
	else {
		jvo->fail(meeting->meetingId);
	}
	return jvo;
}