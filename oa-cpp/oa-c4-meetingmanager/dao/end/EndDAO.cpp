#include "EndDAO.h"

//mt_meeting表中的xmanualCompleted,xactualCompletedTime,xupdateTime需要被修改
//mt_room表中的xavailable需要被修改
int EndDAO::updateEnd(const EndDO& uObj)
{
	string sqlMeeting = "UPDATE \
					`mt_meeting` \
					SET \
						xupdateTime = NOW(), xactualCompletedTime = ?, xmanualCompleted = 1 \
					WHERE \
						xid = ?";
	auto resMeeting = sqlSession->executeUpdate(sqlMeeting, "%s%s", uObj.getActualCompletedTime(), uObj.getMeetingId());

	string sqlRoom = "UPDATE \
					`mt_room` \
					SET \
						xupdateTime = NOW(), xavailable = 1 \
					WHERE \
						xid = ?";
	auto resRoom = sqlSession->executeUpdate(sqlRoom, "%s", uObj.getRoomId());
	
	
	return (resMeeting+resRoom);
}
