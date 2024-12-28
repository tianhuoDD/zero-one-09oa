#pragma once

#ifndef _APPNDICT_DTO_
#define _APPNDICT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 附件传输对象
 */
class AppndictDTO : public oatpp::DTO
{
	DTO_INIT(AppndictDTO, DTO);
	// 编号
	API_DTO_FIELD(UInt64, id, ZH_WORDS_GETTER("appndict.field.id"), true, -1);
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("appndict.field.name"), true, "null");
	API_DTO_FIELD(String, alias, ZH_WORDS_GETTER("appndict.field.alias"), false, "null");
	API_DTO_FIELD(String, desc, ZH_WORDS_GETTER("appndict.field.desc"), true, "null");
	API_DTO_FIELD(UInt64, appId, ZH_WORDS_GETTER("appndict.field.appid"), true, -1);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_APPNDICT_DTO_