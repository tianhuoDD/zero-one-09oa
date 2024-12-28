#pragma once
#ifndef _GETFORM_DTO_
#define _GETFORM_DTO_
#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
	获取栏目表单列表传输对象
	author：toki
*/
class GetFormDTO : public oatpp::DTO {
	DTO_INIT(GetFormDTO, DTO);

	//表单id
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("content.management.field.xid"));
	// 更新时间 (通常由系统设置，不需要传入)
	API_DTO_FIELD_DEFAULT(String, xupdateTime, ZH_WORDS_GETTER("content.management.field.xupdateTime"));
	// 描述 (可修改)
	API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("content.management.field.xdescription"));
	// 别名 (可修改)
	API_DTO_FIELD_DEFAULT(String, xalias, ZH_WORDS_GETTER("content.management.field.xalias"));
	// 应用ID (可修改)
	API_DTO_FIELD_DEFAULT(String, xappId, ZH_WORDS_GETTER("content.management.field.xappId"));

};


class GetFormPageDTO : public PageDTO<GetFormDTO::Wrapper>
{
	DTO_INIT(GetFormPageDTO, PageDTO<GetFormDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif