#include "stdafx.h"
#include "EndService.h"
#include "../../dao/end/EndDAO.h"

bool EndService::updateData(const EndDTO::Wrapper& dto)
{
	// 组装DO数据
	EndDO data;
	/*data.setId(dto->id.getValue(0));
	data.setName(dto->name.getValue(""));
	data.setSex(dto->sex.getValue(""));
	data.setAge(dto->age.getValue(1));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, MeetingId, meetingId, RoomId, roomId, ActualCompletedTime, actualCompleteTime)
		// 执行数据修改
		EndDAO dao;
	return dao.updateEnd(data) == 2;

}
