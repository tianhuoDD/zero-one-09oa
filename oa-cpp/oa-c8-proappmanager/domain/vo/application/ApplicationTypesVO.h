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
	// Ӧ������
	API_DTO_FIELD(String, xapplicationCategory, ZH_WORDS_GETTER("application.field.text"), false, "app-category1");
	// Ӧ������
	API_DTO_FIELD(Int32, xcount, ZH_WORDS_GETTER("application.field.count"), false, 3);
};

class ApplicationTypesListVO : public oatpp::DTO {
	DTO_INIT(ApplicationTypesListVO, DTO);
	// �����б�
	DTO_FIELD(List<ApplicationTypesVO::Wrapper>, rows) = {};
public:
	// �������
	void addData(const ApplicationTypesVO::Wrapper& data) {
		rows->push_back(data);
	}
};

/**
 * Ӧ������JsonVO��������Ӧ���ͻ��˵�Json����
 */
//class ApplicationTypesJsonVO : public JsonVO<ApplicationTypesVO::Wrapper> {
//	DTO_INIT(ApplicationTypesJsonVO, JsonVO<ApplicationTypesVO::Wrapper>);
//};

class ApplicationTypesListJsonVO : public JsonVO<ApplicationTypesListVO::Wrapper> {
	DTO_INIT(ApplicationTypesListJsonVO, JsonVO<ApplicationTypesListVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_APPLICATIONTYPES_VO_