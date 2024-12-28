#pragma once
#pragma once
#pragma once

#ifndef _GROUPLISTDVO_H_
#define _GROUPLISTDVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/get/GroupListDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class GroupListVO : public oatpp::DTO
{
	DTO_INIT(GroupListVO, DTO);
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("grouplist.field.id"), true, "1111");
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("grouplist.field.name"), true, "zhangsan");
	API_DTO_FIELD(String, describe, ZH_WORDS_GETTER("grouplist.field.describe"), false, "okkkkkk");
	
};
class GroupListJsonVO : public JsonVO<GroupListDTO::Wrapper>
{
	DTO_INIT(GroupListJsonVO, JsonVO<GroupListDTO::Wrapper>);
};
/**
 * ������Ϣ��ʾ,������Ӧ���ͻ���jason�����ҳչʾ
 */
class GroupListPageJsonVO : public JsonVO<GroupListPageDTO::Wrapper>
{
	DTO_INIT(GroupListPageJsonVO, JsonVO<GroupListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _PERSONINFOVO_H_
