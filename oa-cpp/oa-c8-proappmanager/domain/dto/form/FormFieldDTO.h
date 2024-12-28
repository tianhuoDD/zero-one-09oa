#pragma once
#ifndef _FORMFIELD_DTO_
#define _FORMFIELD_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个表单列表的数据传输模型
 */
class FormFieldDTO : public oatpp::DTO {
	DTO_INIT(FormFieldDTO, DTO);
	// 名称
	API_DTO_FIELD_DEFAULT(String, name, "name");
	API_DTO_FIELD_DEFAULT(String, dataType, "dataType");
};


#include OATPP_CODEGEN_END(DTO)


#endif // !_FORMFIELD_DTO_
