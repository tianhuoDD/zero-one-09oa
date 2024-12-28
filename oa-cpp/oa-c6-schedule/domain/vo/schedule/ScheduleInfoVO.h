#pragma once
#ifndef _SCHEDULEINFOVO_H_
#define _SCHEDULEINFOVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/schedule/ScheduleInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ScheduleInfoVO : public oatpp::DTO {

	DTO_INIT(ScheduleInfoVO, DTO);
	//�ճ̱�ʶ
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.event.xid"), true, "05640b74-d13f-4a89-b437-2ef6b28e4ae4");
	//������ʶ
	API_DTO_FIELD(String, xcalendarId, ZH_WORDS_GETTER("calender.event.xcalendarId"), true, "066b1ce3-d4b8-42ec-a7bc-4127db1a3239");
	//����
	API_DTO_FIELD(String, xtitle, ZH_WORDS_GETTER("calender.event.xtitle"), true, "title");
	//��ʼʱ��
	API_DTO_FIELD(String, xstartTime, ZH_WORDS_GETTER("calender.event.xstartTime"), true, "2024-10-28 15:00:00");
	//����ʱ��
	API_DTO_FIELD(String, xendTime, ZH_WORDS_GETTER("calender.event.xendTime"), true, "2024-10-28 16:00:00");
	//�ص�
	API_DTO_FIELD(String, xlocationName, ZH_WORDS_GETTER("calender.event.xlocationName"), false, "");
	//�Ƿ�ȫ��
	API_DTO_FIELD(Int32, xisAllDayEvent, ZH_WORDS_GETTER("calender.event.xisAllDayEvent"), false, 0);
	//�Ƿ�����*
	API_DTO_FIELD(Int32, xalarm, ZH_WORDS_GETTER("calender.event.xalarm"), false, 0);
	//���ѷ�ʽ
	API_DTO_FIELD(String, xvalarmTime_config, ZH_WORDS_GETTER("calender.event.xvalarmTime_config"), false, "0,0,0,0");
	//�ظ���ʽ*
	API_DTO_FIELD(String, xrepeat, ZH_WORDS_GETTER("calender.event.xrepeat"), false, "NO");
	//�ظ�����*
	API_DTO_FIELD(String, xrecurrenceRule, ZH_WORDS_GETTER("calender.event.xrecurrenceRule"), false, "");
	//�ظ�����ʱ��*
	API_DTO_FIELD(String, xrepeatUnitDate, ZH_WORDS_GETTER("calender.event.xrepeatUnitDate"), false, "");
	//��ɫ
	API_DTO_FIELD(String, xcolor, ZH_WORDS_GETTER("calender.event.xcolor"), true, "#9072f1");
	//����
	API_DTO_FIELD(String, xcomment, ZH_WORDS_GETTER("calender.event.xcomment"), false, "");

	////id�б�(������id)
	//DTO_FIELD(List<String>, xidList) = { "05640b74-d13f-4a89-b437-2ef6b28e4ae4" };
	//DTO_FIELD_INFO(xidList) {
	//	info->description = ZH_WORDS_GETTER("calender.event.xidList");
	//	info->required = true;
	//}
	//�ظ��Ƿ�����repeatUntilAvailable*
	//API_DTO_FIELD(String, repeatUntilAvailable, ZH_WORDS_GETTER("calender.event.xcomment"), false, "NONE");

	//������*
	DTO_FIELD(List<String>, manegerList) = { "xadmin" };
	DTO_FIELD_INFO(manegerList) {
		info->description = ZH_WORDS_GETTER("calender.event.manegerList");
		info->required = false;
	}
	//�޸Ĳ˵�ѡ��(��ǰ:1������:2)�½����ù�
	API_DTO_FIELD(String, updateMenuOption, ZH_WORDS_GETTER("calender.event.updateMenuOption"), false, "1");
	//�Ƿ�������
	API_DTO_FIELD(String, xalarmAlready, ZH_WORDS_GETTER("calender.event.xalarmAlready"), false, "0");
};

class ScheduleInfoJsonVO : public JsonVO<ScheduleInfoVO::Wrapper> {
	DTO_INIT(ScheduleInfoJsonVO, JsonVO<ScheduleInfoVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SCHEDULEINFOVO_H_
