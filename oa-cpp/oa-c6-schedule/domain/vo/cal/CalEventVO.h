#pragma once
#ifndef _CALEVENTVO_H_
#define _CALEVENTVO_H_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//����һ�����ڻ�ȡ�ճ���Ϣ�Ĵ�������ģ�ͣ������������ֶΣ�


class CalEventVO :public oatpp::DTO
{
	DTO_INIT(CalEventVO, DTO);
	//�ճ���������
	API_DTO_FIELD(String, calendarId, ZH_WORDS_GETTER("calender.event.xcalendarId"), true, "601faa3f-d65f-41b2-85cf-738b065261da");
	
	//�ճ̱���
	API_DTO_FIELD(String, calEventTitle, ZH_WORDS_GETTER("calender.event.xtitle"), true, ZH_WORDS_GETTER("calender.default.default_title"));
	
	//�ճ̿�ʼʱ��
	API_DTO_FIELD(String, calStartTime, ZH_WORDS_GETTER("calender.event.xstartTime"), true, "2024-10-23 18:00:00");
	
	//�ճ̽���ʱ��
	API_DTO_FIELD(String, calEndTime, ZH_WORDS_GETTER("calender.event.xendTime"), true, "2024-10-23 19:00:00");
	
	//�ճ���ʾ��ɫ
	API_DTO_FIELD(String, color, ZH_WORDS_GETTER("calender.event.xcolor"), true, "#f75f59");
	
	//�ճ�����
	API_DTO_FIELD(String, comment, ZH_WORDS_GETTER("calender.event.xcomment"), true, ZH_WORDS_GETTER("calender.default.default_comment"));
	
	//�ճ̵ص�
	API_DTO_FIELD(String, location, ZH_WORDS_GETTER("calender.event.xlocation"), true, ZH_WORDS_GETTER("calender.default.default_location"));
	
	//����ʱ��
	//API_DTO_FIELD(String, valarmTime_config, ZH_WORDS_GETTER("calender.event.xvalarmTime_config"), true, "2024-10-23 17:30:00");
	
	//�ظ�����ÿ�졢ÿ�¡�ÿ��...��
	API_DTO_FIELD(String, recurrenceRule, ZH_WORDS_GETTER("calender.event.xrecurrenceRule"), true, "FREQ=DAILY;UNTIL=20241024T160000Z");
	
	//�Ƿ�ȫ��
	API_DTO_FIELD(Int32, isAllDayEvent, ZH_WORDS_GETTER("calender.event.xisAllDayEvent"), true, 1);
	

};

#include OATPP_CODEGEN_END(DTO)
#endif
