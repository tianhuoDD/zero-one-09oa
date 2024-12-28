#ifndef SENDQUERY
#define SENDQUERY
#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SendQuery : public PageQuery {
	DTO_INIT(SendQuery, PageQuery)
	DTO_FIELD(String, phone);
	DTO_FIELD(String, mail);
	DTO_FIELD(String, type);
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(phone) {
		info->description = "phone";
		info->description = ZH_WORDS_GETTER("send.field.phone");
	}
	DTO_FIELD_INFO(mail) {
		info->description = "mail";
		info->description = ZH_WORDS_GETTER("send.field.mail");
	}
	DTO_FIELD_INFO(type) {
		info->description = "type";
		info->description = ZH_WORDS_GETTER("send.field.type");
	}
	DTO_FIELD_INFO(code) {
		info->description = "code";
		info->description = ZH_WORDS_GETTER("send.field.code");
	}
};;

#include OATPP_CODEGEN_END(DTO)

#endif