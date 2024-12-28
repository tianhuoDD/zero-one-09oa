#pragma once
#ifndef _FORMINFOVO_H_
#define _FORMINFOVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/form/FormInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个表单详情显示JsonVO对象，用于响应给客户端
 */
class FormInfoJsonVO : public JsonVO<FormInfoDTO::Wrapper>
{
	DTO_INIT(FormInfoJsonVO, JsonVO<FormInfoDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _FORMINFOVO_H_