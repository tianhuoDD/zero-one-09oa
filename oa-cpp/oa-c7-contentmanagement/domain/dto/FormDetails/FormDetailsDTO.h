#pragma once
#ifndef _FORMDETAILSDTO_H_
#define _FORMDETAILSDTO_H
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class FormDetailsDTO : public oatpp::DTO {
	DTO_INIT(FormDetailsDTO, DTO);
	//±íµ¥id
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("form.details.bs"));
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("form.details.name"));
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("form.details.description"));
	API_DTO_FIELD_DEFAULT(String, isReadonly, ZH_WORDS_GETTER("form.details.reado"));
	API_DTO_FIELD_DEFAULT(String, formStytleType, ZH_WORDS_GETTER("form.details.ys"));
	API_DTO_FIELD_DEFAULT(String, formIcon, ZH_WORDS_GETTER("form.details.picture"));
	API_DTO_FIELD_DEFAULT(String, xdy, ZH_WORDS_GETTER("form.details.dy"));
	
	

};

#include OATPP_CODEGEN_END(DTO)
#endif