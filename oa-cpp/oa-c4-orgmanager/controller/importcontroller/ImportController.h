#pragma once

#ifndef _IMPORTCONTROLLER_H_
#define _IMPORTCONTROLLER_H_

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "oatpp/web/server/HttpConnectionHandler.hpp"

#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "oatpp/core/macro/codegen.hpp"

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "oatpp/core/data/stream/FileStream.hpp"
#include "oatpp/web/protocol/http/outgoing/Response.hpp"


#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/file/FileResponseVO.h"
#include "domain/dto/file/FileResponseDTO.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ImportController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(ImportController);
public:

	// 导入人员接口
	ENDPOINT_INFO(inputPersonDto)
	{
		info->summary = ZH_WORDS_GETTER("putperson.put.summary");
		API_DEF_ADD_AUTH();

		// 成功响应
		info->addResponse<Object<ImportResponseDTO>>(Status::CODE_200, "application/json");
		// 失败响应
		info->addResponse<Object<ImportResponseDTO>>(Status::CODE_400, "application/json");
	}
	ENDPOINT(API_M_POST, "/x_organization_assemble_control/jaxrs/inputperson", inputPersonDto, REQUEST(std::shared_ptr<IncomingRequest>, request),API_HANDLER_AUTH_PARAME)
	{
		// 权限提取
		std::string id = authObject->getPayload().getId();
		auto authorities = authObject->getPayload().getAuthorities();

		
		// 合法性 以及 excel处理
		auto retDTO = check_validity(request,authorities);
		if ((retDTO->type) == "error")
		{
			auto retVO = ImportResponseVO::createShared();
			retVO->fail(retDTO);
			return createDtoResponse(Status::CODE_400, retVO);
		}else if(retDTO->type=="success")
		{
			auto retVO = ImportResponseVO::createShared();
			retVO->success(retDTO);
			return createDtoResponse(Status::CODE_200, retVO);
		}
	}
	

private:

	ImportResponseDTO::Wrapper check_validity(std::shared_ptr<IncomingRequest> request, std::list<std::string>& authorities);
	ImportResponseVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
};


#include OATPP_CODEGEN_END(ApiController)
#endif#pragma once

#ifndef _IMPORTCONTROLLER_H_
#define _IMPORTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "oatpp/core/data/stream/FileStream.hpp"
#include "oatpp/web/protocol/http/outgoing/Response.hpp"



#include OATPP_CODEGEN_BEGIN(ApiController)

class ImportController : public  oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(ImportController);
public:

	// 导入人员接口
	ENDPOINT_INFO(inputPersonDto)
	{
		info->summary = ZH_WORDS_GETTER("putperson.put.summary");
\
		// 成功响应
		info->addResponse<oatpp::String>(Status::CODE_200, "application/json");
		// 失败响应
		info->addResponse<oatpp::String>(Status::CODE_400, "application/json");
	}
	ENDPOINT(API_M_POST, "/x_organization_assemble_control/jaxrs/inputperson", inputPersonDto, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		//oatpp::data::stream::FileOutputStream fileOutputStream("/path/to/file");
		//request->transferBodyToStream(&fileOutputStream); // transfer body chunk by chunk
		return createResponse(Status::CODE_200, "OK");
	}


private:
	

};

#endif