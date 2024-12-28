#pragma once
#ifndef _CALEVENTSQUEERY_H_
#define _CALEVENTSQUEERY_H_

#include"../../GlobalInclude.h"
#include"domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//����һ����ѯ��־�б�Ķ���

class CalEventsQuery :public PageQuery {
	DTO_INIT(CalEventsQuery, PageQuery);
	//��Ӳ�������������
	DTO_FIELD(String, calendarId);
	DTO_FIELD_INFO(calendarId) {
		info->description = ZH_WORDS_GETTER("calender.event.xcalendarId");
	}
	//��Ӳ�������ѯ������
	DTO_FIELD(String, queryDate);
	DTO_FIELD_INFO(queryDate) {
		info->description = ZH_WORDS_GETTER("calender.event.xqueryDate");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CALENDARQUEERY_H_
