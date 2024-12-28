#pragma once

#ifndef _COLUMN_CONTROLLER_
#define _COLUMN_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ColumnController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(ColumnController);
public:

	// É¾³ýÀ¸Ä¿·ÖÀà
	ENDPOINT_INFO(removeColumn) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("column.delete.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/column/{id}", removeColumn, PATH(UInt64, id), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDeleteColumn(id));
	}
private:
	Uint64JsonVO::Wrapper execDeleteColumn(const UInt64& id);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_COLUMN_CONTROLLER_ 
