#pragma once

#ifndef _MEETINGVO_H_
#define _MEETINGVO_H_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 会议视图对象，用于响应给客户端的JSON对象
 */

class MeetingVOJsonVO : public JsonVO<MeetingDTO::Wrapper> {
	DTO_INIT(MeetingVOJsonVO, JsonVO<MeetingDTO::Wrapper>);


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEETINGVO_H_