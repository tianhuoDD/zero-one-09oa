#pragma once

#ifndef _CALENDERLISTDTO_H_
#define _CALENDERLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	�����б���Ϣ��������
class CalenderListDTO : public oatpp::DTO {
	DTO_INIT(CalenderListDTO, DTO);

	//	����id
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.field.xid"), true, "68");
	//	��������
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("calender.field.xname"), true, "calender_name");
	//	�����б�����
	API_DTO_FIELD(String, xtype, ZH_WORDS_GETTER("calender.field.xtype"), true, ZH_WORDS_GETTER("calender.field.xPresonCalender"));
	//	������ɫ
	API_DTO_FIELD(String, xcolor, ZH_WORDS_GETTER("calender.field.xcolor"), true, "red");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CALENDERLISTDTO_H_

