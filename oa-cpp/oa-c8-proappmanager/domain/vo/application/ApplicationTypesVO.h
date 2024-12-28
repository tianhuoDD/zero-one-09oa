#pragma once

#ifndef _APPLICATIONTYPES_VO_
#define _APPLICATIONTYPES_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/application/ApplicationTypesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//
//class ApplicationTypesVO : public ApplicationTypesDTO {
//	DTO_INIT(ApplicationTypesVO, DTO);
//};

class ApplicationTypesVO : public oatpp::DTO {
	DTO_INIT(ApplicationTypesVO, DTO);
	// 应用类型
	API_DTO_FIELD(String, xapplicationCategory, ZH_WORDS_GETTER("application.field.text"), false, "app-category1");
	// 应用数量
	API_DTO_FIELD(Int32, xcount, ZH_WORDS_GETTER("application.field.count"), false, 3);
};

class ApplicationTypesListVO : public oatpp::DTO {
	DTO_INIT(ApplicationTypesListVO, DTO);
	// 数据列表
	DTO_FIELD(List<ApplicationTypesVO::Wrapper>, rows) = {};
public:
	// 添加数据
	void addData(const ApplicationTypesVO::Wrapper& data) {
		rows->push_back(data);
	}
};

/**
 * 应用类型JsonVO，用于响应给客户端的Json对象
 */
//class ApplicationTypesJsonVO : public JsonVO<ApplicationTypesVO::Wrapper> {
//	DTO_INIT(ApplicationTypesJsonVO, JsonVO<ApplicationTypesVO::Wrapper>);
//};

class ApplicationTypesListJsonVO : public JsonVO<ApplicationTypesListVO::Wrapper> {
	DTO_INIT(ApplicationTypesListJsonVO, JsonVO<ApplicationTypesListVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_APPLICATIONTYPES_VO_