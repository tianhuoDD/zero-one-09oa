#pragma once
#ifndef _ATTACHMENT_DO_
#define _ATTACHMENT_DO_
#include "../DoInclude.h"
class AttachmentDO {
	//附件唯一标识符
	CC_SYNTHESIZE(string, id, Id);
	//文件名
	CC_SYNTHESIZE(string, name, Name);
	
	//最后更新时间
	CC_SYNTHESIZE(string, lastUpdateTime, LastUpdateTime);
	//最后更新人
	CC_SYNTHESIZE(string, lastUpdatePerson, LastUpdatePerson);
	//文件密钥
	CC_SYNTHESIZE(string, encryptKey, EncryptKey);
	
	//是否使用深层路径
	CC_SYNTHESIZE(bool, deepPath, DeepPath);
	
	//文件拓展名
	CC_SYNTHESIZE(string, extension, Extension);
	
	//文件大小
	CC_SYNTHESIZE(uint64_t, length, Length);
	//文件存储标识
	CC_SYNTHESIZE(string, storage, Storage);
	//是否有文件描述
	CC_SYNTHESIZE(bool, summary, Summary);
	//关联的会议id
	CC_SYNTHESIZE(string, meetingId, MeetingId);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
public:
	AttachmentDO() :id(""), name(""), lastUpdateTime(""), lastUpdatePerson(""), meetingId(""),createTime(""),
		encryptKey(""), deepPath(false), extension(""), length(0), storage(""), summary(false){}
};

#endif // ! _ATTACHMENT_DO_
