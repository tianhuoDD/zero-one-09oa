#pragma once

#ifndef _CALENDERINFOVO_H_
#define _CALENDERINFOVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/calender/CalenderInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//	������Ϣ��ʾ����
class CalenderInfoVO : public oatpp::DTO {
	DTO_INIT(CalenderInfoVO, DTO);

	//	����ID������ƺ�������ʾ
	//API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("calender.field.xid"));
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
	API_DTO_FIELD(String, xview, ZH_WORDS_GETTER("calender.field.xview"), false, "");
	//	���½���Χ
	API_DTO_FIELD(String, xpublish, ZH_WORDS_GETTER("calender.field.xpublish"), false, "");
	//	�Ƿ�����
	API_DTO_FIELD(String, xstatus, ZH_WORDS_GETTER("calender.field.xstatus"), true, "yes");
	//	����ʱ��
	//API_DTO_FIELD(String, xcreatetime, ZH_WORDS_GETTER("calender.field.xcreatetime"), true, "yyyy-mm-dd");
	//	����ʱ��
	//API_DTO_FIELD(String, xupdatetime, ZH_WORDS_GETTER("calender.field.xupdatetime"), true, "yyyy-mm-dd");
};

/**
 * ����״̬��ʾ��Ϣ
 */
#ifdef LINUX
#define RS_CALENDERNAME_FAIL ResultStatus(u8"the calendar name cannot be empty", 9991)
#define RS_CALENDERXTARGETRMPTY_FAIL ResultStatus(u8"the organization field cannot be empty", 9992)
#define RS_CALENDERDESCRIPTION_FAIL ResultStatus(u8"the description is too long", 9993)
#else
#define RS_CALENDERNAME_FAIL ResultStatus(u8"�������Ʋ���Ϊ��", 9991)
#define RS_CALENDERXTARGETRMPTY_FAIL ResultStatus(u8"������֯����Ϊ��", 9992)
#define RS_CALENDERDESCRIPTION_FAIL ResultStatus(u8"��ע����", 9993)
#endif

//	������Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
class CalenderInfoJsonVo : public JsonVO<CalenderInfoDTO::Wrapper> {
	DTO_INIT(CalenderInfoJsonVo, JsonVO<CalenderInfoDTO::Wrapper>);

	// ���ݶ���
	DTO_FIELD(CalenderInfoDTO::Wrapper, data, "data");
	DTO_FIELD_INFO(data) {
#ifndef LINUX
		info->description = u8"���ݶ���";
#else
		info->description = "data object";
#endif
	}

public:
	// ����״̬
	void setStatus(ResultStatus resultStatus) {
		this->message = resultStatus.getMessage();
		this->code = resultStatus.getCode();
	}
	// ��ʼ��
	void init(ResultStatus resultStatus) {
		this->setStatus(resultStatus);
	}
	// �����ɹ���Ϣ
	void success(CalenderInfoDTO::Wrapper data) {
		this->setStatus(RS_SUCCESS);
		this->data = data;
	}
	// ���ع����ɹ���Ϣ
	void success() {
		this->setStatus(RS_SUCCESS);
	}

	// ����ʧ����Ϣ
	void fail(uint64_t data) {
		if (88 == data)
		{
			this->setStatus(RS_PARAMS_INVALID);
		}
		else
			this->setStatus(RS_FAIL);
	}

};

#include OATPP_CODEGEN_END(DTO)




#endif // !_CALENDERINFOVO_H_