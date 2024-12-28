#pragma once
#ifndef _ATTACHMENT_DO_
#define _ATTACHMENT_DO_
#include "../DoInclude.h"
class AttachmentDO {
	//����Ψһ��ʶ��
	CC_SYNTHESIZE(string, id, Id);
	//�ļ���
	CC_SYNTHESIZE(string, name, Name);
	
	//������ʱ��
	CC_SYNTHESIZE(string, lastUpdateTime, LastUpdateTime);
	//��������
	CC_SYNTHESIZE(string, lastUpdatePerson, LastUpdatePerson);
	//�ļ���Կ
	CC_SYNTHESIZE(string, encryptKey, EncryptKey);
	
	//�Ƿ�ʹ�����·��
	CC_SYNTHESIZE(bool, deepPath, DeepPath);
	
	//�ļ���չ��
	CC_SYNTHESIZE(string, extension, Extension);
	
	//�ļ���С
	CC_SYNTHESIZE(uint64_t, length, Length);
	//�ļ��洢��ʶ
	CC_SYNTHESIZE(string, storage, Storage);
	//�Ƿ����ļ�����
	CC_SYNTHESIZE(bool, summary, Summary);
	//�����Ļ���id
	CC_SYNTHESIZE(string, meetingId, MeetingId);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
public:
	AttachmentDO() :id(""), name(""), lastUpdateTime(""), lastUpdatePerson(""), meetingId(""),createTime(""),
		encryptKey(""), deepPath(false), extension(""), length(0), storage(""), summary(false){}
};

#endif // ! _ATTACHMENT_DO_
