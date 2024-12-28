#pragma once
#ifndef __ATTACHMENTADDDTO_H__
#define __ATTACHMENTADDDTO_H__

#include "domain/GlobalInclude.h"
// ����dto�Ŀ�ʼ
#include OATPP_CODEGEN_BEGIN(DTO)

class AttachmentAddDTO : public oatpp::DTO {
	DTO_INIT(AttachmentAddDTO, DTO); // ��ʼ��DTO
	/*// �����ֶ� oatpp ��ʽ�����ֶ�
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = "the onely id";
	}*/
	// ���κ� ��ʽ����
	// ����Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("attachment.field.id"));
	// ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("attachment.field.name"));
	// ����
	API_DTO_FIELD_DEFAULT(String, alais, ZH_WORDS_GETTER("attachment.field.alais"));
	// ������Ϣ
	API_DTO_FIELD_DEFAULT(String, attachmentInfo, ZH_WORDS_GETTER("attachment.field.attachmentInfo"));
	//  ����
	API_DTO_FIELD_DEFAULT(String, attachment, ZH_WORDS_GETTER("attachment.field.attachment"));
	// URL
	//API_DTO_FIELD_DEFAULT(String, URL, ZH_WORDS_GETTER("attachment.field.URL"));
};
#include OATPP_CODEGEN_END(DTO)

#endif

