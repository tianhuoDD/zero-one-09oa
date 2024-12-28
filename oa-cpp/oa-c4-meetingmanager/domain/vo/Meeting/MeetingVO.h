#pragma once

#ifndef _MEETINGVO_H_
#define _MEETINGVO_H_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ͼ����������Ӧ���ͻ��˵�JSON����
 */

class MeetingVOJsonVO : public JsonVO<MeetingDTO::Wrapper> {
	DTO_INIT(MeetingVOJsonVO, JsonVO<MeetingDTO::Wrapper>);


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEETINGVO_H_