#pragma once

#ifndef _APPNDICT_QUERY_
#define _APPNDICT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 附件分页查询对象
 */
class AppndictQuery : public PageQuery
{
	DTO_INIT(AppndictQuery, PageQuery);
	// 姓名
	API_DTO_FIELD(UInt64, id, ZH_WORDS_GETTER("appndict.field.id"), true, -1);
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("appndict.field.name"), true, "null");
	API_DTO_FIELD(String, alias, ZH_WORDS_GETTER("appndict.field.alias"), false, "null");
	API_DTO_FIELD(String, desc, ZH_WORDS_GETTER("appndict.field.desc"), true, "null");
	API_DTO_FIELD(UInt64, appId, ZH_WORDS_GETTER("appndict.field.appid"), true, -1);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_APPNDICT_QUERY_