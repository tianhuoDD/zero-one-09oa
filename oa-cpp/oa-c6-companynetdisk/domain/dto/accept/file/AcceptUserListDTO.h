#pragma once
#ifndef _ACCEPTUSERLISTDTO_H_
#define _ACCEPTUSERLISTDTO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AcceptUserListDTO : public oatpp::DTO
{
	DTO_INIT(AcceptUserListDTO, DTO);
	//初始化读取器和容器
	//用户唯一id
	API_DTO_FIELD(String, ATTACHMENT_XID, ZH_WORDS_GETTER("accept.file.id"), false, "33333");
	//文件上传人
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("accept.file.xperson"), false, "xiaoma");

};

class AcceptUsersPageDTO : public PageDTO<AcceptUserListDTO::Wrapper>
{
	DTO_INIT(AcceptUsersPageDTO, PageDTO<AcceptUserListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_