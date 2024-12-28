#pragma once
#pragma once
#pragma once

#ifndef _ADDPERSON_H_
#define _ADDPERSON_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/query/PageQuery.h"

#include"domain/GlobalInclude.h"
#include"../../domain/dto/Person/add/PersonInfoDTO.h"
#include"service/AddServe/AddServe.h"
#include"SnowFlake.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class AddPersonController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(AddPersonController);
public://����ӿ�
	 

	ENDPOINT_INFO(addPerson) {
		info->summary = ZH_WORDS_GETTER("person.add.summary");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

	}
	ENDPOINT(API_M_POST, "personal-management/add-person", addPerson, BODY_DTO(PersioninfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		
		API_HANDLER_RESP_VO(execAddPerson(dto));
	}
private: 
	 
	Uint64JsonVO::Wrapper execAddPerson(const PersioninfoDTO::Wrapper& dto);



};

#include OATPP_CODEGEN_END(ApiController)

#endif  