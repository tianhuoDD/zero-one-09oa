#pragma once

#ifndef _MYFILEVO_H_
#define _MYFILEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/myfile/MyfileDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class MyfileJsonVO : public JsonVO<MyfileDTO::Wrapper>
{
	DTO_INIT(MyfileJsonVO, JsonVO<MyfileDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MYFILEVO_H_