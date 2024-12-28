#pragma once
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "domain/GlobalInclude.h"
#include "../arch-demo/domain/dto/user/UserDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ProcessSettingVO : public oatpp::DTO
{
	DTO_INIT(ProcessSettingVO, DTO);

	//VO
	API_DTO_FIELD_DEFAULT(String, application, "process.setting.field.application");

	API_DTO_FIELD_DEFAULT(String, creatorPerson, "process.setting.field.creatorPerson");

	API_DTO_FIELD_DEFAULT(String, createTime, "process.setting.field.createTime");

	API_DTO_FIELD_DEFAULT(String, lastUpdatePerson, "process.setting.field.lastUpdatePerson");

	API_DTO_FIELD_DEFAULT(String, lastUpdateTime, "process.setting.field.lastUpdateTime");
	//DTO
	API_DTO_FIELD_DEFAULT(String, name, "process.setting.field.name");

	API_DTO_FIELD_DEFAULT(String, nickname, "process.setting.field.nickname");

	API_DTO_FIELD_DEFAULT(String, classfy, "process.setting.field.classfy");

	API_DTO_FIELD_DEFAULT(String, describe, "process.setting.field.describe");

	API_DTO_FIELD_DEFAULT(String, icon, "process.setting.field.icon");

};

class ProcessSettingJsonVO : public JsonVO<ProcessSettingVO::Wrapper>
{
	DTO_INIT(ProcessSettingJsonVO, JsonVO<ProcessSettingVO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif