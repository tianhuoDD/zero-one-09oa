#pragma once
#ifndef _ATTRIB_VOS_
#define _ATTRIB_VOS_

#include "../../GlobalInclude.h"
#include "../../dto/Attrib_modify/Attrib_modify_DTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class Attrib_modify_JsonVO : public JsonVO<Attrib_modify_DTO::Wrapper> {
	DTO_INIT(Attrib_modify_JsonVO, JsonVO<Attrib_modify_DTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_