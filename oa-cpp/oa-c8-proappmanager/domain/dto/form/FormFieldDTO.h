#pragma once
#ifndef _FORMFIELD_DTO_
#define _FORMFIELD_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ�����б�����ݴ���ģ��
 */
class FormFieldDTO : public oatpp::DTO {
	DTO_INIT(FormFieldDTO, DTO);
	// ����
	API_DTO_FIELD_DEFAULT(String, name, "name");
	API_DTO_FIELD_DEFAULT(String, dataType, "dataType");
};


#include OATPP_CODEGEN_END(DTO)


#endif // !_FORMFIELD_DTO_
