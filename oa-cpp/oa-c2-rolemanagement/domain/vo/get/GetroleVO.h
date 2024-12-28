#pragma once
#ifndef _GETROLEVO_H_
#define _GETROLEVO_H_

#include "../../GlobalInclude.h" //二层目录
#include "domain/dto/get/GetroleDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)//标记DTO类定义的宏


class GetroleVO :public oatpp::DTO
{
	DTO_INIT(GetroleVO, DTO);


	//角色名称
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("addroleDTO.field.name"), false, "");
	//唯一编码
	API_DTO_FIELD(String, key, ZH_WORDS_GETTER("addroleDTO.field.key"), true, ""); 
	//角色描述
	API_DTO_FIELD(String, refer, ZH_WORDS_GETTER("addroleDTO.field.refer"), false, "");

	API_DTO_FIELD(String, fullName, ZH_WORDS_GETTER("addroleDTO.field.fullName"), false, "");

	//角色创建于
	API_DTO_FIELD(String, startTime, ZH_WORDS_GETTER("addroleDTO.field.startTime"), false, "");

	//最后修改于
	API_DTO_FIELD(String, endTime, ZH_WORDS_GETTER("addroleDTO.field.endTime"), false, "");



};




//个人信息显示JsonVO
class GetroleJsonVO : public JsonVO<GetroleVO::Wrapper> {
	DTO_INIT(GetroleJsonVO, JsonVO<GetroleVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETROLEVO_H_
