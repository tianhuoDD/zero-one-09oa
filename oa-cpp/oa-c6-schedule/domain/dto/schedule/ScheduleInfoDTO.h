#ifndef _SCHEDULEINFODTO_H_
#define _SCHEDULEINFODTO_H_
	
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ScheduleInfoDTO : public oatpp::DTO {

	DTO_INIT(ScheduleInfoDTO, DTO);
	//日程标识
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.event.xid"), true, "05640b74-d13f-4a89-b437-2ef6b28e4ae4");
	//重复日程id
	API_DTO_FIELD(String, xrepmId, ZH_WORDS_GETTER("calender.event.xrepmId"), true, "74876b58-3fe0-429b-9957-58194fb07f27");
	//日历标识
	API_DTO_FIELD(String, xcalendarId, ZH_WORDS_GETTER("calender.event.xcalendarId"), true, "3765f1c8-fbdf-4ca2-aef3-182b29f30a4b");
	//标题
	API_DTO_FIELD(String, xtitle, ZH_WORDS_GETTER("calender.event.xtitle"), true, "title");
	//开始时间
	API_DTO_FIELD(String, xstartTime, ZH_WORDS_GETTER("calender.event.xstartTime"), true, "2024-10-28 15:00:00");
	//结束时间
	API_DTO_FIELD(String, xendTime, ZH_WORDS_GETTER("calender.event.xendTime"), true, "2024-10-28 16:00:00");
	//地点
	API_DTO_FIELD(String, xlocationName, ZH_WORDS_GETTER("calender.event.xlocationName"), false, "");
	//是否全天
	API_DTO_FIELD(Int32, xisAllDayEvent, ZH_WORDS_GETTER("calender.event.xisAllDayEvent"), false, 0);
	//是否提醒*
	API_DTO_FIELD(Int32, xalarm, ZH_WORDS_GETTER("calender.event.xalarm"), false, 0);
	//提醒方式
	API_DTO_FIELD(String, xvalarmTime_config, ZH_WORDS_GETTER("calender.event.xvalarmTime_config"), false, "0,0,0,0");
	//重复方式*
	API_DTO_FIELD(String, xrepeat, ZH_WORDS_GETTER("calender.event.xrepeat"), false, "NO");
	//重复规则
	API_DTO_FIELD(String, xrecurrenceRule, ZH_WORDS_GETTER("calender.event.xrecurrenceRule"), false, "");
	//重复结束时间*
	API_DTO_FIELD(String, xrepeatUnitDate, ZH_WORDS_GETTER("calender.event.xrepeatUnitDate"), false, "");
	//颜色
	API_DTO_FIELD(String, xcolor, ZH_WORDS_GETTER("calender.event.xcolor"), true, "#9072f1");
	//内容
	API_DTO_FIELD(String, xcomment, ZH_WORDS_GETTER("calender.event.xcomment"), false, "");

	////id列表(处理多个id)
	//DTO_FIELD(List<String>, xidList) = { "05640b74-d13f-4a89-b437-2ef6b28e4ae4" };
	//DTO_FIELD_INFO(xidList) {
	//	info->description = ZH_WORDS_GETTER("calender.event.xidList");
	//	info->required = true;
	//}
	//重复是否永久repeatUntilAvailable*
	//API_DTO_FIELD(String, repeatUntilAvailable, ZH_WORDS_GETTER("calender.event.xcomment"), false, "NONE");
	
	//管理人*
	DTO_FIELD(List<String>, manegerList) = { "xadmin" };
	DTO_FIELD_INFO(manegerList) {
		info->description = ZH_WORDS_GETTER("calender.event.manegerList");
		info->required = false;
	}
	//修改菜单选项(当前:1，所有:2)新建不用管
	API_DTO_FIELD(String, updateMenuOption, ZH_WORDS_GETTER("calender.event.updateMenuOption"), false, "1");
	//是否已提醒
	API_DTO_FIELD(String, xalarmAlready, ZH_WORDS_GETTER("calender.event.xalarmAlready"), false, "0");

};

class ScheduleDelDTO : public oatpp::DTO {

	DTO_INIT(ScheduleDelDTO, DTO);
	//日程标识
	//API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.event.xid"), true, "05640b74-d13f-4a89-b437-2ef6b28e4ae4");
	//修改菜单选项(当前:1，所有:2)新建不用管
	API_DTO_FIELD(String, updateMenuOption, ZH_WORDS_GETTER("calender.event.updateMenuOption"), false, "1");

	//重复日程id
	API_DTO_FIELD(String, xrepmId, ZH_WORDS_GETTER("calender.event.xrepmId"), true, "74876b58-3fe0-429b-9957-58194fb07f27");

	//id列表(处理多个id)
	DTO_FIELD(List<String>, xidList) = { "05640b74-d13f-4a89-b437-2ef6b28e4ae4" };
	DTO_FIELD_INFO(xidList) {
		info->description = ZH_WORDS_GETTER("calender.event.xidList");
		info->required = true;
	}

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SCHEDULEINFODTO_H_
