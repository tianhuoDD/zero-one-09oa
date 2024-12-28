#pragma once
#ifndef _ATTRIB_CONTROLLERS_
#define _ATTRIB_CONTROLLERS_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Attrib_modify/Attrib_modify_DTO.h"
#include "domain/vo/Attrib_modify/Attrib_modify_VO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class Attrib_modify_Controller : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(Attrib_modify_Controller);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyAttrib) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Attrib_modify.title.modify"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/c1-org/Attrib_modify", modifyAttrib, BODY_DTO(Attrib_modify_DTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyAttrib(dto));
	}
private:
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyAttrib(const Attrib_modify_DTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 