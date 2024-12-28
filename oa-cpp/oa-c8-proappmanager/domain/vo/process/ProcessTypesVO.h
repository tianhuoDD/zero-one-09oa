#pragma once
#ifndef _PROCESSTYPES_VO_
#define _PROCESSTYPES_VO_

#include "domain/GlobalInclude.h"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

// ����������ʾ����
class ProcessTypesVO : public oatpp::DTO {
	DTO_INIT(ProcessTypesVO, DTO);
	// ��������
	API_DTO_FIELD(String, xcategory, ZH_WORDS_GETTER("process-configuration.process-types.field.category"), false, "A");
	// ��������
	API_DTO_FIELD(Int32, containNums, ZH_WORDS_GETTER("process-configuration.process-types.field.contain-nums"), false, 10);

};

// ����������ʾ���󼯺�
class ProcessTypesListVO : oatpp::DTO {
	DTO_INIT(ProcessTypesListVO, DTO);

	// ���ݵ�������
	DTO_FIELD(Int64, total) = 9;
	DTO_FIELD_INFO(total) {
		info->required = true;
#ifndef LINUX
		info->description = u8"���ݵ�������";
#else
		info->description = "total";
#endif
	}
	// �����б�
	DTO_FIELD(List<ProcessTypesVO::Wrapper>, rows) = {};

	DTO_FIELD_INFO(rows) {
#ifndef LINUX
		info->description = u8"�����б�";
#else
		info->description = "data list";
#endif
	}
public:
	ProcessTypesListVO() {
		this->total = v_int64(0);
	}
	// ����������������
	void setTotal(UInt64 total) {
		this->total = v_int64(total);
	}
	// ���һ������
	void addData(const ProcessTypesVO::Wrapper& data) {
		rows->push_back(data);
	}
};

// ����������ʾJsonVO, ������Ӧ���ͻ��˵�Json����
class ProcessTypesJsonVO : public JsonVO<ProcessTypesVO::Wrapper> {
	DTO_INIT(ProcessTypesJsonVO, JsonVO<ProcessTypesVO::Wrapper>);
};

// ����������ʾJsonVO����, ������Ӧ���ͻ��˵�Json����
class ProcessTypesListJsonVO : public JsonVO<ProcessTypesListVO::Wrapper> {
	DTO_INIT(ProcessTypesListJsonVO, JsonVO<ProcessTypesListVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSTYPES_VO_
