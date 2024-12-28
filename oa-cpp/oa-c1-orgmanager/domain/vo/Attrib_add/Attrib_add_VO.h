#pragma once
#ifndef _ATTRIB_VO_
#define _ATTRIB_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Attrib_add/Attrib_add_DTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class Attrib_add_JsonVO : public JsonVO<Attrib_add_DTO::Wrapper> {
	DTO_INIT(Attrib_add_JsonVO, JsonVO<Attrib_add_DTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_