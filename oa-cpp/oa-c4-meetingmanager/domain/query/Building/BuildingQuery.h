#pragma once
#ifndef _BUILDING_QUERY_
#define _BUILDING_QUERY_

#include "../../GlobalInclude.h"
#include "domain/dto/Building/BuildingDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BuildingQuery : public oatpp::DTO {
	DTO_INIT(BuildingQuery, oatpp::DTO);
	//��ȡ���л�����λ�õ����о���������б�
	DTO_FIELD(list<oatpp::Object<BuildInfo>>, data);
	DTO_FIELD_INFO(data) {
		info->description = ZH_WORDS_GETTER("");
	}
	//��ȡ������
	DTO_FIELD(String, date);
	DTO_FIELD_INFO(date) {
		info->description = ZH_WORDS_GETTER("");
	}
	// ���ݴ�С
	DTO_FIELD(Int32, size);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_BUILDING_QUERY_