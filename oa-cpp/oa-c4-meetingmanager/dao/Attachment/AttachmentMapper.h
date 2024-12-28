#pragma once
#ifndef _ATTACHMENT_MAPPER_H_
#define _ATTACHMENT_MAPPER_H_
#include "Mapper.h"
#include"domain/do/Attachment/AttachmentDO.h"
class AttachmentMapper : Mapper<AttachmentDO> {
public:
	AttachmentDO mapper(ResultSet* resultSet) const override {
		AttachmentDO attachmentDO;
		attachmentDO.setId(resultSet->getString(1));
		attachmentDO.setName(resultSet->getString(2));
		attachmentDO.setExtension(resultSet->getString(3));
		attachmentDO.setLastUpdateTime(resultSet->getString(4));
		attachmentDO.setLastUpdatePerson(resultSet->getString(5));
		attachmentDO.setDeepPath(resultSet->getBoolean(6));
		attachmentDO.setEncryptKey(resultSet->getString(7));
		attachmentDO.setStorage(resultSet->getString(8));
		attachmentDO.setLength(resultSet->getUInt64(9));
		attachmentDO.setSummary(resultSet->getBoolean(10));
		attachmentDO.setMeetingId(resultSet->getString(11));
		attachmentDO.setCreateTime(resultSet->getString(12));
		return attachmentDO;
	}
};



#endif // !_ATTACHMENT_MAPPER_H_
