#pragma once
#ifndef _ATTACHMENTOPERATE_DTO_
#define _ATTACHMENTOPERATE_DTO_

#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class AttachmentOperateDTO : public oatpp::DTO {
	DTO_INIT(AttachmentOperateDTO, DTO);
	// 附件唯一标识
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("process.attachments.field.id"), true, "");
	// 名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("process.attachments.field.name"));
	// 别名
	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("process.attachments.field.alias"));
	API_DTO_FIELD(String, application, ZH_WORDS_GETTER("process.attachments.field.application"), true, "");
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("process.attachments.field.description"));
	API_DTO_FIELD_DEFAULT(String, fileName, ZH_WORDS_GETTER("process.attachments.field.fileName"));
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("process.attachments.field.createTime"));
	API_DTO_FIELD_DEFAULT(String, lastUpdatePerson, ZH_WORDS_GETTER("process.attachments.field.lastUpdatePerson"));
	API_DTO_FIELD_DEFAULT(String, lastUpdateTime, ZH_WORDS_GETTER("process.attachments.field.lastUpdateTime"));
	API_DTO_FIELD_DEFAULT(UInt64, length, ZH_WORDS_GETTER("process.attachments.field.length"));
	API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("process.attachments.field.xupdateTime"));
	API_DTO_FIELD_DEFAULT(String, sequence, ZH_WORDS_GETTER("process.attachments.field.sequence"));
	API_DTO_FIELD_DEFAULT(UInt64, distributeFactor, ZH_WORDS_GETTER("process.attachments.field.distributeFactor"));
	API_DTO_FIELD_DEFAULT(String, data, ZH_WORDS_GETTER("process.attachments.field.data"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ATTACHMENTOPERATE_DTO_
