#pragma once
#ifndef _FORMLISTVO_H_
#define _FORMLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/form/FormListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ�����б��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class FormListPageJsonVO :public JsonVO<FormListPageDTO::Wrapper>
{
	DTO_INIT(FormListPageJsonVO, JsonVO<FormListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _FORMINFOVO_H_