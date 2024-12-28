#pragma once
#ifndef _ACCEPTFILELISTVO_H_
#define _ACCEPTFILELISTVO_H_
#include "../../../GlobalInclude.h"
#include "../../../dto/accept/file/AcceptFileListDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)


/*
	将文件的信息显示JsonVO，用于响应给客户端的Json对象
*/
class AcceptFileListJsonVO : public JsonVO<AcceptFilesPageDTO::Wrapper>
{
	DTO_INIT(AcceptFileListJsonVO, JsonVO<AcceptFilesPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_

