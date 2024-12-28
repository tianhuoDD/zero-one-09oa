#pragma once
#ifndef _CALENDARFOLLOWDTO_H_
#define _CALENDARFOLLOWDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	������Ϣ��������
class CalendarFollowDTO : public oatpp::DTO {
	DTO_INIT(CalendarFollowDTO, DTO);
	//	����ID
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.field.xid"), true, "123");
	//  ��ѯ��ID
	API_DTO_FIELD(String, xfollowersId, ZH_WORDS_GETTER("calender.field.xfollowers"), false , "");
	//  ���ȼ�����
	API_DTO_FIELD(Int8, xorderColumn, ZH_WORDS_GETTER("calender.field.xorderColumn"), false, static_cast <v_int8>(0));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CALENDARFOLLOWDTO_H_