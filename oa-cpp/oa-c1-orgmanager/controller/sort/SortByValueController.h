#pragma once

#ifndef _SortByValue_Controller_
#define _SortByValue_Controller_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Sort/SortByValue.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class SortByValueController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(SortByValueController);
	// 3 ����ӿ�
public:
	// �����޸���ְ֯��ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sort.sort_value"), sortValue, Uint64JsonVO::Wrapper);
	// �����޸���ְ֯��ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c1-org/sortValue", sortValue, BODY_DTO(SortByValueDTO::Wrapper, dto), execSortByValue(dto));
private:
	Uint64JsonVO::Wrapper execSortByValue(const SortByValueDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_