#pragma once

#ifndef _CALENDERCREATECONTROLLER_H
#define _CALENDERCREATECONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/calender/CalenderInfoDTO.h"
#include "domain/vo/calender/CalenderInfoVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class CalenderCreateController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	//  ����������������
	API_ACCESS_DECLARE(CalenderCreateController);

public:
	// �޸�������Ϣ�ӿ�
		//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("calender.put.summary"), modifyCalenderInfo, StringJsonVO::Wrapper);
	ENDPOINT_INFO(modifyCalenderInfo) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("calender.put.summary"), Uint64JsonVO::Wrapper);
	}
	// �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/schedule/modify-calender", modifyCalenderInfo, BODY_DTO(CalenderInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeModifyCalenderInfo(dto, authObject->getPayload().getXsequence()));
	}
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/calender-create/modify-calender", modifyCalenderInfo, BODY_DTO(CalenderInfoDTO::Wrapper, dto), executeModifyCalenderInfo(dto, authObject->getPayload().getXsequence()));

	//���������ӿ�����
	ENDPOINT_INFO(addCalenderInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/schedule/create-calender", addCalenderInfo, BODY_DTO(CalenderInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		//std::cout << authObject->getPayload().getXsequence() << std::endl;
		API_HANDLER_RESP_VO(execAddCalender(dto, authObject->getPayload().getXsequence()));
	}

	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeCalender) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("calender.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "xid", ZH_WORDS_GETTER("calender.field.xid"), "123aaa", true);
	}
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/schedule/del-calender/{xid}", removeCalender, PATH(String, xid), execRemoveCalender(xid));

private:
	// ִ���޸�������Ϣ
	CalenderInfoJsonVo::Wrapper executeModifyCalenderInfo(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName);
	// ��������
	CalenderInfoJsonVo::Wrapper execAddCalender(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName);
	//ɾ������
	Uint64JsonVO::Wrapper execRemoveCalender(const String& xid);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CALENDERCREATECONTROLLER_H
