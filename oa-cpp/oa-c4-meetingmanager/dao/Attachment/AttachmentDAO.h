#pragma once
#ifndef _ATTACHMENT_DAO_
#define _ATTACHMENT_DAO_
#include "BaseDAO.h"
#include "domain/do/Attachment/AttachmentDO.h"
#include "dao/Attachment/AttachmentMapper.h"
#include<string>
class AttachmentDAO :public BaseDAO
{
public:
	//通过会议的唯一ID去查询文件信息
	list<AttachmentDO> selectByMeetingId(const string& meetingId);
	//通过会议Id删除文件信息
	int deleteByAttachmentId(const string& attachmentId);
	//插入文件信息
	uint64_t insert(AttachmentDO& attachmentDO);
};
#endif