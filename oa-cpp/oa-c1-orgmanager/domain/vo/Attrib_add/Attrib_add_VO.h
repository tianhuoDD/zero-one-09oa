#pragma once
#ifndef _ATTRIB_VO_
#define _ATTRIB_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Attrib_add/Attrib_add_DTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class Attrib_add_JsonVO : public JsonVO<Attrib_add_DTO::Wrapper> {
	DTO_INIT(Attrib_add_JsonVO, JsonVO<Attrib_add_DTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_