#pragma once

#ifndef _CALENDERLISTVO_H
#define _CALENDERLISTVO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	日历列表显示对象
class CalenderListVO : public oatpp::DTO {
	DTO_INIT(CalenderListVO, DTO);

	//	日历ID
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.field.xid"), true, "68");
	//	日历名称
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("calender.field.xname"), true, "calender_name");
	//	日历列表类型
	API_DTO_FIELD(String, xtype, ZH_WORDS_GETTER("calender.field.xtype"), true, ZH_WORDS_GETTER("calender.field.xPresonCalender"));
	//	日历颜色
	API_DTO_FIELD(String, xcolor, ZH_WORDS_GETTER("calender.field.xcolor"), true, "red");
};

//	日历列表显示JsonVO，用于响应给客户端的Json对象
class CalenderListJsonVO : public JsonVO<oatpp::List<CalenderListDTO::Wrapper>> {
	DTO_INIT(CalenderListJsonVO, JsonVO<oatpp::List<CalenderListDTO::Wrapper>>);

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CALENDERLISTVO_H
