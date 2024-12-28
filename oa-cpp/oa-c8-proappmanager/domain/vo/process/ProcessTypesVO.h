#pragma once
#ifndef _PROCESSTYPES_VO_
#define _PROCESSTYPES_VO_

#include "domain/GlobalInclude.h"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

// 流程类型显示对象
class ProcessTypesVO : public oatpp::DTO {
	DTO_INIT(ProcessTypesVO, DTO);
	// 流程类型
	API_DTO_FIELD(String, xcategory, ZH_WORDS_GETTER("process-configuration.process-types.field.category"), false, "A");
	// 流程数量
	API_DTO_FIELD(Int32, containNums, ZH_WORDS_GETTER("process-configuration.process-types.field.contain-nums"), false, 10);

};

// 流程类型显示对象集合
class ProcessTypesListVO : oatpp::DTO {
	DTO_INIT(ProcessTypesListVO, DTO);

	// 数据的总条数
	DTO_FIELD(Int64, total) = 9;
	DTO_FIELD_INFO(total) {
		info->required = true;
#ifndef LINUX
		info->description = u8"数据的总条数";
#else
		info->description = "total";
#endif
	}
	// 数据列表
	DTO_FIELD(List<ProcessTypesVO::Wrapper>, rows) = {};

	DTO_FIELD_INFO(rows) {
#ifndef LINUX
		info->description = u8"数据列表";
#else
		info->description = "data list";
#endif
	}
public:
	ProcessTypesListVO() {
		this->total = v_int64(0);
	}
	// 设置数据类型总数
	void setTotal(UInt64 total) {
		this->total = v_int64(total);
	}
	// 添加一条数据
	void addData(const ProcessTypesVO::Wrapper& data) {
		rows->push_back(data);
	}
};

// 流程类型显示JsonVO, 用于响应给客户端的Json对象
class ProcessTypesJsonVO : public JsonVO<ProcessTypesVO::Wrapper> {
	DTO_INIT(ProcessTypesJsonVO, JsonVO<ProcessTypesVO::Wrapper>);
};

// 流程类型显示JsonVO集合, 用于响应给客户端的Json对象
class ProcessTypesListJsonVO : public JsonVO<ProcessTypesListVO::Wrapper> {
	DTO_INIT(ProcessTypesListJsonVO, JsonVO<ProcessTypesListVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSTYPES_VO_
