#pragma once
#ifndef __ATTACHMENTADDDTO_H__
#define __ATTACHMENTADDDTO_H__

#include "domain/GlobalInclude.h"
// 引入dto的开始
#include OATPP_CODEGEN_BEGIN(DTO)

class AttachmentAddDTO : public oatpp::DTO {
	DTO_INIT(AttachmentAddDTO, DTO); // 初始化DTO
	/*// 定义字段 oatpp 方式定义字段
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = "the onely id";
	}*/
	// 二次宏 方式定义
	// 附件唯一标识
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("attachment.field.id"));
	// 名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("attachment.field.name"));
	// 别名
	API_DTO_FIELD_DEFAULT(String, alais, ZH_WORDS_GETTER("attachment.field.alais"));
	// 附件信息
	API_DTO_FIELD_DEFAULT(String, attachmentInfo, ZH_WORDS_GETTER("attachment.field.attachmentInfo"));
	//  附件
	API_DTO_FIELD_DEFAULT(String, attachment, ZH_WORDS_GETTER("attachment.field.attachment"));
	// URL
	//API_DTO_FIELD_DEFAULT(String, URL, ZH_WORDS_GETTER("attachment.field.URL"));
};
#include OATPP_CODEGEN_END(DTO)

#endif

