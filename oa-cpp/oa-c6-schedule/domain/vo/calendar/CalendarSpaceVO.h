#pragma once
#ifndef _CALENDARSPACE_VO_
#define _CALENDARSPACE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/calendar/CalendarSpaceDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ӧ���ͻ��˵�Json����
 */
class CalendarSpaceJsonVO : public JsonVO<CalendarSpaceDTO::Wrapper> {
	DTO_INIT(CalendarSpaceJsonVO, JsonVO<CalendarSpaceDTO::Wrapper>);
};

/**
 * ������Ӧ���ͻ��˵�Json����
 */
class CalendarSpacePageJsonVO : public JsonVO<CalendarSpacePageDTO::Wrapper> {
	DTO_INIT(CalendarSpacePageJsonVO, JsonVO<CalendarSpacePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CALENDARSPACE_VO_