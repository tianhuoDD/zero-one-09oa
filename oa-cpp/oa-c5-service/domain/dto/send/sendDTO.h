#pragma once
#ifndef _SEND_DTO_
#define _SEND_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SendDTO : public oatpp::DTO
{
	DTO_INIT(SendDTO, DTO);

	DTO_FIELD(List<oatpp::String>, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("send.field.phone");
	}

	DTO_FIELD(String, mail);
	DTO_FIELD_INFO(mail) {
		info->description = ZH_WORDS_GETTER("send.field.mail");
	}
	// 消息类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("send.field.type");
	}
	// 验证码
	DTO_FIELD(List<oatpp::String>, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("send.field.code");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_