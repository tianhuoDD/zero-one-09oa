#pragma once
#pragma once
#pragma once
#pragma once

#ifndef _DELETEPERSON_H_
#define _DELETEPERSON_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/query/PageQuery.h"

#include"domain/GlobalInclude.h"
#include"../../domain/dto/Person/add/PersonInfoDTO.h"
#include"service/AddServe/AddServe.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class DeletePersonController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DeletePersonController);
public://����ӿ�

	//����˵�
	ENDPOINT_INFO(deletePerson) {
		info->summary = ZH_WORDS_GETTER("person.delete.summary");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("person.delete.id"), 1, true);
	}
	ENDPOINT(API_M_DEL, "personal-management/delete-derson/{id}", deletePerson, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execDeletePerson(id));
	}
 
	 

private: // ����ӿ�ִ�к���

	Uint64JsonVO::Wrapper execDeletePerson(const String& id);



};

#include OATPP_CODEGEN_END(ApiController)

#endif  