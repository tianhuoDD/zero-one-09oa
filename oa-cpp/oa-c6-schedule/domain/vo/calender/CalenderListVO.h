#pragma once

#ifndef _CALENDERLISTVO_H
#define _CALENDERLISTVO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	�����б���ʾ����
class CalenderListVO : public oatpp::DTO {
	DTO_INIT(CalenderListVO, DTO);

	//	����ID
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.field.xid"), true, "68");
	//	��������
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("calender.field.xname"), true, "calender_name");
	//	�����б�����
	API_DTO_FIELD(String, xtype, ZH_WORDS_GETTER("calender.field.xtype"), true, ZH_WORDS_GETTER("calender.field.xPresonCalender"));
	//	������ɫ
	API_DTO_FIELD(String, xcolor, ZH_WORDS_GETTER("calender.field.xcolor"), true, "red");
};

//	�����б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
class CalenderListJsonVO : public JsonVO<oatpp::List<CalenderListDTO::Wrapper>> {
	DTO_INIT(CalenderListJsonVO, JsonVO<oatpp::List<CalenderListDTO::Wrapper>>);

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CALENDERLISTVO_H
