#pragma once

#ifndef _APPNDICT_VO_
#define _APPNDICT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/appndict/AppndictDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AppndictJsonVO : public JsonVO<AppndictDTO::Wrapper> {
	DTO_INIT(AppndictJsonVO, JsonVO<AppndictDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPNDICT_VO_