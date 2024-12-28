#pragma once
#ifndef _ACCEPTUSERLISTVO_H_
#define _ACCEPTUSERLISTVO_H_
#include "../../../GlobalInclude.h"
#include "../../../dto/accept/file/AcceptUserListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
	将文件的信息显示JsonVO，用于响应给客户端的Json对象
*/
class AcceptUserListJsonVO : public JsonVO<AcceptUsersPageDTO::Wrapper>
{
	DTO_INIT(AcceptUserListJsonVO, JsonVO<AcceptUsersPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_