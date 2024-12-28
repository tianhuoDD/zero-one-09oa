#pragma once
#ifndef _PROCESSSETTING_DTO_
#define _PROCESSSETTING_DTO_


#include "domain/GlobalInclude.h"
#include "../arch-demo/domain/dto/user/UserDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ProcessSettingDTO : public oatpp::DTO
{
	DTO_INIT(ProcessSettingDTO, DTO);

	//DTO
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("process.setting.field.name"));

	API_DTO_FIELD_DEFAULT(String, nickname, ZH_WORDS_GETTER("process.setting.field.nickname"));

	API_DTO_FIELD_DEFAULT(String, classfy, ZH_WORDS_GETTER("process.setting.field.classfy"));

	API_DTO_FIELD_DEFAULT(String, describe, ZH_WORDS_GETTER("process.setting.field.describe"));

	API_DTO_FIELD_DEFAULT(String, icon, ZH_WORDS_GETTER("process.setting.field.icon"));

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSSETTING_DTO_