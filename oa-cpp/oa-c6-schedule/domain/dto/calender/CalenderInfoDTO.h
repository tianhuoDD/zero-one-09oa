#pragma once

#ifndef _CALENDERINFODTO_H_
#define _CALENDERINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	������Ϣ��������
class CalenderInfoDTO : public oatpp::DTO {
	DTO_INIT(CalenderInfoDTO, DTO);

	//	����ID
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("calender.field.xid"), true, "123");
	//	��������
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("calender.field.xname"), true, "aaa");
	//	��ɫ
	API_DTO_FIELD(String, xcolor, ZH_WORDS_GETTER("calender.field.xcolor"), true, "red");
	//	����
	API_DTO_FIELD(String, xtype, ZH_WORDS_GETTER("calender.field.xtype"), true, "PERSON");
	//	�Ƿ񹫿�
	API_DTO_FIELD(Int32, xisPublic, ZH_WORDS_GETTER("calender.field.xisPublic"), true, 1);
	//	��ע
	API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("calender.field.xdescription"), false, "");
	//	������֯
	API_DTO_FIELD(String, xtarget, ZH_WORDS_GETTER("calender.field.xtarget"), true, "admin");
	//	������
	API_DTO_FIELD(String, xmanageablePersonList, ZH_WORDS_GETTER("calender.field.xmanageablePersonList"), true, "x@1@P");
	//	�ɼ���Χ
	API_DTO_FIELD(String, xview, ZH_WORDS_GETTER("calender.field.xview"), false, "person unit group");
	//	���½���Χ
	API_DTO_FIELD(String, xpublish, ZH_WORDS_GETTER("calender.field.xpublish"), false, "person unit group");
	//	�Ƿ�����
	API_DTO_FIELD(String, xstatus, ZH_WORDS_GETTER("calender.field.xstatus"), true, "yes");
	//	����ʱ��
	//API_DTO_FIELD(String, xcreatetime, ZH_WORDS_GETTER("calender.field.xcreatetime"), true, "yyyy-mm-dd");
	//	����ʱ��
	//API_DTO_FIELD(String, xupdatetime, ZH_WORDS_GETTER("calender.field.xupdatetime"), true, "yyyy-mm-dd");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CALENDERINFODTO_H_