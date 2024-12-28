#pragma once
#ifndef _ADDAPPLICATION_DTO_
#define _ADDAPPLICATION_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddApplicationDTO : public oatpp::DTO {
	DTO_INIT(AddApplicationDTO, DTO);

	// 应用名称
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("application.field.name");
	}
	// 应用别名
	DTO_FIELD(String, xalias);
	DTO_FIELD_INFO(xalias) {
		info->description = ZH_WORDS_GETTER("application.field.alias");
	}
	// 应用类型
	DTO_FIELD(String, xapplicationCategory);
	DTO_FIELD_INFO(xapplicationCategory) {
		info->description = ZH_WORDS_GETTER("application.field.applicationCategory");
	}

	DTO_FIELD(String, xdescription);
	DTO_FIELD_INFO(xdescription) {
		info->description = ZH_WORDS_GETTER("application.field.description");
	}

};


#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDAPPLICATION_DTO_
