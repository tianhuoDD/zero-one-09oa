#pragma once
#ifndef _CALENDARFOLLOW_CONTROLLER_
#define _CALENDARFOLLOW_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/calendar/CalendarFollowDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class CalendarFollowController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CalendarFollowController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(addFollow) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.post.follow"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ����������ѯ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_POST, "/schedule/calendar-space-addfollow", addFollow, BODY_DTO(CalendarFollowDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddFollow(dto, authObject->getPayload()));
	}

	ENDPOINT_INFO(removeFollow) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.delete.follow"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ����������ѯ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_DEL, "/schedule/calendar-space-removefollow", removeFollow, BODY_DTO(CalendarFollowDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execRemoveFollow(dto, authObject->getPayload()));
	}
private:
	// 3.3 ������ע
	Uint64JsonVO::Wrapper execAddFollow(const CalendarFollowDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 �Ƴ���ע
	Uint64JsonVO::Wrapper execRemoveFollow(const CalendarFollowDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CALENDARFOLLOW_CONTROLLER_