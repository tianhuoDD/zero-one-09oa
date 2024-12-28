#pragma once

#ifndef _APPLICATIONTYPES_DTO_
#define _APPLICATIONTYPES_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Ӧ�����ʹ������
 */
class ApplicationTypesDTO : public oatpp::DTO
{
	DTO_INIT(ApplicationTypesDTO, DTO);

	//Ӧ������  
	//API_DTO_FIELD_DEFAULT(String, xapplicationCategory, ZH_WORDS_GETTER("application-info.pp_e_application.field.xapplicationCategory"));
	API_DTO_FIELD(String, xapplicationCategory, ZH_WORDS_GETTER("application-info.pp_e_application.field.xapplicationCategory"),false,"app-category1");

	//Ӧ������  
	//API_DTO_FIELD_DEFAULT(Int32, xcount, ZH_WORDS_GETTER("application-info.pp_e_application.field.xcount"));
	API_DTO_FIELD(Int32, xcount, ZH_WORDS_GETTER("application-info.pp_e_application.field.xcount"),false,3);

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATIONTYPES_DTO_
