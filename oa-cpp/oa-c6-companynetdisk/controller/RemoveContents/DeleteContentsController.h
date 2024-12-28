#pragma once

#ifndef _DeleteContents_CONTROLLER_
#define _DeleteContents_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
//#include "../../domain/query/sample/SampleQuery.h"
#include "domain/dto/remove/CdeleteDTO.h"
#include "domain/vo/remove/CdeleteVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DeleteContentsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteContentsController);
	// 3 ����ӿ�
public:

	// 3.1 ���� ɾ��Ŀ¼ �ӿ�����
	ENDPOINT_INFO(DeleteContent) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Myfile.delete.summary"), StringJsonVO::Wrapper);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/companynetdisk/delete-folder/{xid}", DeleteContent, PATH(String, xid), execRemoveSample(xid));


	// 3.1 ���� ������Ŀ¼ �ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Myfile.rename.summary"), modifySample, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/companynetdisk/modify-folder", modifySample, BODY_DTO(CdeleteDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));
private:
	// ɾ��Ŀ¼ �ӿ� ִ�к���
	StringJsonVO::Wrapper execRemoveSample(const String& xid);
	// ������Ŀ¼ �ӿ� ִ�к���
	StringJsonVO::Wrapper execModifySample(const CdeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	//StringJsonVO
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_


