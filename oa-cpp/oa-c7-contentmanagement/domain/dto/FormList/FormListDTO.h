#pragma once
#ifndef _FORMLISTDTO_H_
#define _FORMLISTDTO_H
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class FormListDTO : public oatpp::DTO {
	DTO_INIT(FormListDTO, DTO);
	//±íµ¥id
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("form.list.xid"));
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("form.list.xname"));
	API_DTO_FIELD_DEFAULT(String, xalias, ZH_WORDS_GETTER("form.list.xalias"));
	API_DTO_FIELD_DEFAULT(String, xcreatetime, ZH_WORDS_GETTER("form.list.xcreatetime"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif