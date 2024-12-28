#include "stdafx.h"
#include "AddMeetingController.h"
#include "../../service/Meeting/AddCelMeetingService.h"

StringJsonVO::Wrapper AddMeetingController::execAddMeeting(const MeetingDTO::Wrapper& dto) {
	AddCelMeetingService service;

	auto jvo = StringJsonVO::createShared();
	//����service�㴦��
	jvo = service.addMeeting(dto);


	if (jvo->data.getValue("") == "success") {
		jvo->success(ZH_WORDS_GETTER("jvo.create.success"));
	}
	else
	{
		if (jvo->data.getValue("") == "") {
			jvo->fail(ZH_WORDS_GETTER("jvo.create.fail"));
		}
		else
			jvo->setStatus(RS_FAIL);
	}
	// ��Ӧ���
	return jvo;
}