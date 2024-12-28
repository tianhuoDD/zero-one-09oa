#pragma once

#ifndef _EXPORTCONTROLLER_H_
#define _EXPORTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "oatpp/web/protocol/http/outgoing/BufferBody.hpp"
#include "oatpp/web/protocol/http/Http.hpp"

#include "../../lib-common/include/ExcelComponent.h"

#include <oatpp/core/data/stream/BufferStream.hpp>


#include OATPP_CODEGEN_BEGIN(ApiController)

class ExportController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(ExportController);
public:

	ENDPOINT_INFO(exportPerson)
	{
		info->summary = ZH_WORDS_GETTER("exportperson.get.summary");

        API_DEF_ADD_AUTH();
		// �ɹ���Ӧ������excel�ļ�
        info->addResponse<oatpp::String>(Status::CODE_200, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");   // ������Ӧ�����ͺͷ��ص�״̬��
        // ʧ����Ӧ
        info->addResponse<oatpp::String>(Status::CODE_403, "text/plain");
	}

	
    ENDPOINT(API_M_GET, "/x_organization_assemble_control/jaxrs/exportperson", exportPerson, API_HANDLER_AUTH_PARAME)
    {
        //// �ȼ���Ƿ�������excel��Ȩ��
        //std::list<std::string> authorities = authObject->getPayload().getAuthorities();
        //if (!check_permission(authorities))	// û��Ȩ��
        //    return createResponse(Status::CODE_403, "Forbidden");


        // �õ�excel�Ķ�����
        auto bodyStr = get_excel_binary();


        // ������Ӧ
        auto response = createResponse(Status::CODE_200, bodyStr);
        response->putHeader("Content-Type", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
        response->putHeader("Content-Disposition", "attachment; filename=\"exportperson.xlsx\"");

        return response;
    }

private:
    bool check_permission(std::list<std::string> authorities);
    oatpp::String get_excel_binary();

};

#include OATPP_CODEGEN_END(ApiController)
#endif