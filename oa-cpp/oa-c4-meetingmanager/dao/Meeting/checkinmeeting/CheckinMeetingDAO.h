#pragma once

#ifndef _CHECKINMEETING_DAO_
#define _CHECKINMEETING_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/Meeting/checkinmeeting/CheckinMeetingDO.h"

/**
 * ����ǩ�������ݿ����ʵ��
 */
class CheckinMeetingDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const CheckinMeetingDO& iObj);
};

#endif // !_CHECKINMEETING_DAO_