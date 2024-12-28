#pragma once
#ifndef _ADDROLE_DTO_
#define _ADDROLE_DTO_

#include "../../../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddroleDTO : public oatpp::DTO {
	DTO_INIT(AddroleDTO, DTO);

	// 角色名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.name");
	}

	// 唯一编码
	DTO_FIELD(String, unique);
	DTO_FIELD_INFO(unique) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.key");
	}

	// 角色描述
	DTO_FIELD(String, description);
	DTO_FIELD_INFO(description) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.refer");
	}
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_ADDROLE_DTO_