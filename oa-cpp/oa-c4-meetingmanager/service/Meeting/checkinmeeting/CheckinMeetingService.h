#pragma once

#ifndef _CHECKINMEETING_SERVICE_
#define _CHECKINMEETING_SERVICE_
#include <list>

#include "domain/dto/Meeting/checkinmeeting/CheckinMeetingDTO.h"

/**
 * ����ǩ������ʵ��
 */
class CheckinMeetingService
{
public:
	// ��������
	uint64_t saveData(const CheckinMeetingDTO::Wrapper& dto);
};

#endif // !_CHECKINMEETING_SERVICE_