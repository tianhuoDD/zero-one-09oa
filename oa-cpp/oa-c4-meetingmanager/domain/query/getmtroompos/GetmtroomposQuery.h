#pragma once

#ifndef _GETMTROOMPOSQUERY_QUERY_
#define _GETMTROOMPOSQUERY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 会议室位置分页查询对象
 */
class GetmtroomposQuery : public PageQuery
{
	DTO_INIT(GetmtroomposQuery, PageQuery);
	// 会议室位置
	DTO_FIELD(String, xid);
	DTO_FIELD(String, xaddress);
	DTO_FIELD(String, xname);
	//DTO_FIELD_INFO(xid) {
	//	info->description = ZH_WORDS_GETTER("mtroom.get.xname");
	//}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETMTROOMPOSQUERY_QUERY_