#pragma once
#ifndef _ATTRIB_CONTROLLER_
#define _ATTRIB_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Attrib_add/Attrib_add_DTO.h"
#include "domain/vo/Attrib_add/Attrib_add_VO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class Attrib_add_Controller : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(Attrib_add_Controller);
	// 3 ����ӿ�
public:
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addAttrib) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Attrib_add.title.add"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���  API_HANDLER_AUTH_PARAME
	ENDPOINT(API_M_POST, "/c1-org/Attrib_add", addAttrib, BODY_DTO(Attrib_add_DTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddAttrib(dto));
	}
private:
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddAttrib(const Attrib_add_DTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_