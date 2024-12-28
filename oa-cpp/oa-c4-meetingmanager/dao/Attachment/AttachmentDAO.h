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
	//ͨ�������ΨһIDȥ��ѯ�ļ���Ϣ
	list<AttachmentDO> selectByMeetingId(const string& meetingId);
	//ͨ������Idɾ���ļ���Ϣ
	int deleteByAttachmentId(const string& attachmentId);
	//�����ļ���Ϣ
	uint64_t insert(AttachmentDO& attachmentDO);
};
#endif