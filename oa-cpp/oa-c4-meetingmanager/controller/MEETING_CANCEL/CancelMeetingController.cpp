#include "CancelMeetingController.h"
#include "../../service/Meeting/AddCelMeetingService.h"

StringJsonVO::Wrapper CancelMeetingController::execCancelMeeting(const string& id) {
	AddCelMeetingService service;

	auto jvo = StringJsonVO::createShared();
	jvo = service.celMeeting(id);
	if (jvo->data.getValue("") != "error") {
		jvo->success(ZH_WORDS_GETTER("jvo.cancel.success"));
	}
	else
	{
		jvo->fail(ZH_WORDS_GETTER("jvo.cancel.fail"));
	}
	// ÏìÓ¦½á¹û
	return jvo;
}