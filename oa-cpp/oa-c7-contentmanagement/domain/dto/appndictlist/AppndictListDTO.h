#pragma once

#ifndef _APPNDICTLIST_DTO_
#define _APPNDICTLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 附件传输对象
 */
class AppndictListDTO : public oatpp::DTO
{
	DTO_INIT(AppndictListDTO, DTO);
	// 编号
	API_DTO_FIELD(UInt64, id, ZH_WORDS_GETTER("appndict.field.id"), true, -1);
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("appndict.field.name"), true, "null");
	API_DTO_FIELD(String, desc, ZH_WORDS_GETTER("appndict.field.desc"), true, "null");
	API_DTO_FIELD(String, uTime, ZH_WORDS_GETTER("appndict.field.utime"), true, "null");
	API_DTO_FIELD(UInt64, appId, ZH_WORDS_GETTER("appndict.field.appid"), true, -1);
};

/**
 * 附件分页传输对象
 */
class AppndictListPageDTO : public PageDTO<AppndictListDTO::Wrapper> 
{
	DTO_INIT(AppndictListPageDTO, PageDTO<AppndictListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_APPNDICTLIST_DTO_