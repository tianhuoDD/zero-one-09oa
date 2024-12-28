#include "EndDAO.h"

//mt_meeting���е�xmanualCompleted,xactualCompletedTime,xupdateTime��Ҫ���޸�
//mt_room���е�xavailable��Ҫ���޸�
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
