#pragma once

#ifndef _GROUPLISTDTO_H_
#define _GROUPLISTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class GroupListDTO : public oatpp::DTO
{
	DTO_INIT(GroupListDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("grouplist.field.id"));
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("grouplist.field.name"));
	API_DTO_FIELD_DEFAULT(String, describe, ZH_WORDS_GETTER("grouplist.field.describe"));

};

/**
 * 示例分页传输对象
 */

class GroupListPageDTO : public PageDTO<GroupListDTO::Wrapper>
{
	DTO_INIT(GroupListPageDTO, PageDTO<GroupListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // _GROUPLISTDTO_H_