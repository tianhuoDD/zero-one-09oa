#pragma once

#ifndef _APPNDICT_VO_
#define _APPNDICT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/appndict/AppndictDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 附件显示JsonVO，用于响应给客户端的Json对象
 */
class AppndictJsonVO : public JsonVO<AppndictDTO::Wrapper> {
	DTO_INIT(AppndictJsonVO, JsonVO<AppndictDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPNDICT_VO_