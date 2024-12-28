#pragma once

#ifndef _RenameFile_CONTROLLER_
#define _RenameFile_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
//#include "../../domain/query/sample/SampleQuery.h"
#include "domain/dto/remove/DdeleteDTO.h"
#include "domain/vo/remove/DdeleteVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class RenameFileController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RenameFileController);
	// 3 ����ӿ�
public:
	// 3.1 ���� �������ļ� �ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Myfile.rename.summary_file"), modifySample, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/companynetdisk/modify-file", modifySample, BODY_DTO(DdeleteDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));
private:
	// �������ļ� �ӿ� ִ�к���
	StringJsonVO::Wrapper execModifySample(const DdeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	//StringJsonVO
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

