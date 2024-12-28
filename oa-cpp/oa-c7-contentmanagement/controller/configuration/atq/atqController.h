#pragma once

#ifndef  _ATQCONTROLLER
#define  _ATQCONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include"domain/vo/configuration/atq/configurationVo.h"
#include"domain/dto/configuration/atq/configurationDto.h"
#include "../../../service/configuration/atq/ConfigurationService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class atqController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(atqController);
public: // ����ӿ�
    //��ȡ��Ŀ�����б�ӿ�
    // 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryConfiguration) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("configuration.atq.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ConfigurationPageJsonVO);
		// ���尴���ļ���ʶ��ѯ����
		API_DEF_ADD_QUERY_PARAMS(String, "logo", ZH_WORDS_GETTER("configuration.atq.basic.logo"), "abc", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/configuration/atq", queryConfiguration, QUERY(String, logo), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execucateconfigquery(logo));
	}
//�޸���Ŀ����ӿ�
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("configuration.atq.put.summary"), modifyconfiguration,StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/configuration/atq", modifyconfiguration, BODY_DTO(ConfigurationDTO::Wrapper, dto), execucatemodify(dto));
//������Ŀ����ӿ�
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addConfiguration) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("configuration.atq.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/configuration/atq", addConfiguration, BODY_DTO(ConfigurationDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execucateadd(dto));
	}

	// ɾ����Ŀ����ӿ�
	ENDPOINT_INFO(removeConfiguration) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("configuration.atq.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("configuration.atq.basic.logo"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sample/{id}", removeConfiguration, PATH(String, id), execRemoveConfiguration(id));

private: // ����ӿ�ִ�к���
	//ִ�л�ȡ��Ŀ�����б�
	ConfigurationPageJsonVO::Wrapper execucateconfigquery(const String& logo);
	//ִ���޸���Ŀ����ӿ�
	StringJsonVO::Wrapper execucatemodify(const ConfigurationDTO::Wrapper& dto);
	//������Ŀ����ӿ�
	Uint64JsonVO::Wrapper execucateadd(const ConfigurationDTO::Wrapper& dto);
	// ɾ����Ŀ����ӿ�
	Uint64JsonVO::Wrapper execRemoveConfiguration(const String& logo);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //