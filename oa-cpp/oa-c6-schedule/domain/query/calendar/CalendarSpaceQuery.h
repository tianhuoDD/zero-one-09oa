#pragma once
#ifndef _CALENDARSPACE_QUERY_
#define _CALENDARSPACE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class CalendarSpaceQuery : public PageQuery
{
	DTO_INIT(CalendarSpaceQuery, PageQuery);
	//	��ѯ������
	API_DTO_FIELD(String, xfollowersId, ZH_WORDS_GETTER("calender.field.xfollowers"), false, "1");
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CALENDARSPACE_QUERY_