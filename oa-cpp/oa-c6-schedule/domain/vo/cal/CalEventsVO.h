#pragma once

#ifndef _CALEVENTSVO_H_
#define _CALEVENTSVO_H_



//��vo���ڽ��ղ�ѯ������־�б���������־


#include "../../GlobalInclude.h"
#include "../../../../lib-oatpp/include/oatpp/core/macro/codegen.hpp"
#include "../../../../lib-oatpp/include/oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

//����һ�����ڻ�ȡ�ճ���Ϣ�Ĵ�������ģ�ͣ������������ֶΣ�
class CalEventsVO :public oatpp::DTO
{
	DTO_INIT(CalEventsVO, DTO);
	//�ճ�id��������
	API_DTO_FIELD(String, calEventId, ZH_WORDS_GETTER("calender.event.xid"), true, "2fe6315f-2d53-406e-a605-bf48895e4d7b");
	//�ճ̱���
	API_DTO_FIELD(String, calEventTitle, ZH_WORDS_GETTER("calender.event.xtitle"), true, ZH_WORDS_GETTER("cal.default.default_title"));

	//�ճ̿�ʼʱ��
	API_DTO_FIELD(String, calStartTime, ZH_WORDS_GETTER("calender.event.xstartTime"), true, "2024-10-23 18:00:00");

	//�ճ̽���ʱ��
	API_DTO_FIELD(String, calEndTime, ZH_WORDS_GETTER("calender.event.xendTime"), true, "2024-10-23 19:00:00");

	//�ճ���ʾ��ɫ
	API_DTO_FIELD(String, color, ZH_WORDS_GETTER("calender.event.xcolor"), true, "#f75f59");

	//�ճ̵ص�
	API_DTO_FIELD(String, location, ZH_WORDS_GETTER("calender.event.xlocation"), true, ZH_WORDS_GETTER("cal.default.default_location"));

	//����ʱ��
	//API_DTO_FIELD(String, valarmTime_config, ZH_WORDS_GETTER("calender.event.xvalarmTime_config"), true, "2024-10-23 17:30:00");

	//�Ƿ�ȫ��
	API_DTO_FIELD(Int32, isAllDayEvent, ZH_WORDS_GETTER("calender.event.xisAllDayEvent"), true, 1);
};



//����һ�����ڻ�ȡ�ճ���Ϣ���ϵĶ���(�����ڼ�����һ����ȫ��)
//��������ǻ����������־�����

class CalAllEventsVO :public oatpp::DTO
{
	DTO_INIT(CalAllEventsVO, DTO);
	API_DTO_FIELD(Int64, total, ZH_WORDS_GETTER("calender.event.event_total"), true, 1);
	API_DTO_FIELD(List<CalEventsVO::Wrapper>, event_rows, ZH_WORDS_GETTER("calender.event.event_rows"), true, {});

public:
	void addData(CalEventsVO::Wrapper vo) {
		this->event_rows->push_back(vo);
	}
};


#include OATPP_CODEGEN_END(DTO)

#endif
