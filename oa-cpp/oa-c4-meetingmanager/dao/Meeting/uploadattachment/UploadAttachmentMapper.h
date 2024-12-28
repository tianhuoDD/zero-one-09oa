#pragma once
#ifndef _UPLOADATTACHMENTDAO_MAPPER_
#define _UPLOADATTACHMENTDAO_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/Meeting/uploadattachment/UploadAttachmentDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class UploadAttachmentMapper : public Mapper<UploadAttachmentDO>
{
public:
	UploadAttachmentDO mapper(ResultSet* resultSet) const override
	{
		UploadAttachmentDO data;
		data.setXid(resultSet->getString(1));
		data.setXcreateTime(resultSet->getString(2));
		data.setXsequence(resultSet->getString(3));
		data.setXupdateTime(resultSet->getString(4));
		data.setXdeepPath(resultSet->getInt(5));
		data.setXextension(resultSet->getString(6));
		data.setXlastUpdatePerson(resultSet->getString(7));
		data.setXlastUpdateTime(resultSet->getString(8));
		data.setXlength(resultSet->getInt64(9));
		data.setXmeeting(resultSet->getString(10));
		data.setXname(resultSet->getString(11));
		data.setXstorage(resultSet->getString(12));
		data.setXsummary(resultSet->getBoolean(13));
		return data;
	}
};

#endif // !_UPLOADATTACHMENTDAO_MAPPER_