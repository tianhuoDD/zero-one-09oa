#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 25日 星期五 19:27:32 CST
*/
#ifndef _ADDPERSON_VO_
#define _ADDPERSON_VO_

#include "../../GlobalInclude.h"
#include "../../dto/put/AddPersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class AddPersonJsonVO : public JsonVO<AddPersonDTO::Wrapper> {
	DTO_INIT(AddPersonJsonVO, JsonVO<AddPersonDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDPERSON_VO_