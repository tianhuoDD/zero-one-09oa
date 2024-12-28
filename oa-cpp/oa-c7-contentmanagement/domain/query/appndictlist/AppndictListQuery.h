#pragma once

#ifndef _APPNDICTLIST_QUERY_
#define _APPNDICTLIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 附件分页查询对象
 */
class AppndictListQuery : public PageQuery
{
	DTO_INIT(AppndictListQuery, PageQuery);
	// 姓名
	API_DTO_FIELD(UInt64, id, ZH_WORDS_GETTER("appndict.field.id"), true, -1);
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("appndict.field.name"), true, "null");
	API_DTO_FIELD(String, desc, ZH_WORDS_GETTER("appndict.field.desc"), true, "null");
	API_DTO_FIELD(String, uTime, ZH_WORDS_GETTER("appndict.field.utime"), true, "null");
	API_DTO_FIELD(UInt64, appId, ZH_WORDS_GETTER("appndict.field.appid"), true, -1);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_APPNDICTLIST_QUERY_