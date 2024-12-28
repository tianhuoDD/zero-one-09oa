#pragma once
#ifndef _ATTACHMENTDETAIL_VO_
#define _ATTACHMENTDETAIL_VO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ϸ��ʾ����
 */
class AttachmentDetailVO : public oatpp::DTO {
	DTO_INIT(AttachmentDetailVO, DTO);

	// ����Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("process.attachments.field.id"));
	// ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("process.attachments.field.name"));
	//
	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("process.attachments.field.alias"));
	//
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("process.attachments.field.description"));
	// 
	API_DTO_FIELD_DEFAULT(String, application, ZH_WORDS_GETTER("process.attachments.field.application"));
	// 
	API_DTO_FIELD_DEFAULT(String, lastUpdatePerson, ZH_WORDS_GETTER("process.attachments.field.lastUpdatePerson"));
	// 
	API_DTO_FIELD_DEFAULT(String, lastUpdateTime, ZH_WORDS_GETTER("process.attachments.field.lastUpdateTime"));
	// 
	API_DTO_FIELD_DEFAULT(String, fileName, ZH_WORDS_GETTER("process.attachments.field.fileName"));
	// 
	API_DTO_FIELD_DEFAULT(UInt64, length, ZH_WORDS_GETTER("process.attachments.field.length"));
	// 
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("process.attachments.field.createTime"));
	//
	API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("process.attachments.field.xupdateTime"));
	API_DTO_FIELD_DEFAULT(String, data, ZH_WORDS_GETTER("process.attachments.field.data"));
};

/**
 * ������ϸ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AttachmentDetailJsonVO : public JsonVO<AttachmentDetailVO::Wrapper> {
	DTO_INIT(AttachmentDetailJsonVO, JsonVO<AttachmentDetailVO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_ATTACHMENTDETAIL_VO_