#pragma once

#ifndef _APPNDICTLIST_VO_
#define _APPNDICTLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/appndictlist/AppndictListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 附件分页显示JsonVO，用于响应给客户端的Json对象
 */
class AppndictListPageJsonVO : public JsonVO<AppndictListPageDTO::Wrapper> {
	DTO_INIT(AppndictListPageJsonVO, JsonVO<AppndictListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPNDICTLIST_VO_