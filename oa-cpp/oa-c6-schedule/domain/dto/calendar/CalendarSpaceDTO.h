#pragma once
#ifndef _CALENDARSPACEDTO_H_
#define _CALENDARSPACEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	日历信息操作对象
class CalendarSpaceDTO : public oatpp::DTO {
	DTO_INIT(CalendarSpaceDTO, DTO);
	//	日历ID
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.field.xid"), true, "123");
	//	创建时间
	API_DTO_FIELD(String, xcreatetime, ZH_WORDS_GETTER("calender.field.xcreatetime"), true, "yyyy-mm-dd");
	//	颜色
	API_DTO_FIELD(String, xcolor, ZH_WORDS_GETTER("calender.field.xcolor"), true, "red");
	//  新建
	API_DTO_FIELD(String, xcreateor, ZH_WORDS_GETTER("calender.field.xcreateor"), true, "1");
	//	日历名称
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("calender.field.xname"), true, "aaa");
	//	类型
	API_DTO_FIELD(String, xtype, ZH_WORDS_GETTER("calender.field.xtype"), true, "Person");
	//	备注
	API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("calender.field.xdescription"), false, "");
	//  是否关注
	API_DTO_FIELD(String, xisfollow, ZH_WORDS_GETTER("calender.field.xisfollow"), true, "");
};

class CalendarSpacePageDTO : public PageDTO<CalendarSpaceDTO::Wrapper>
{
	DTO_INIT(CalendarSpacePageDTO, PageDTO<CalendarSpaceDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CALENDARSPACEDTO_H_