#pragma once

#ifndef _ROLERESOURCEVO_H_
#define _ROLERESOURCEVO_H_

#include "../../../GlobalInclude.h"
#include "tree/TreeNode.h"
#include "../../../dto/post/roleresource/RoleResourceInfoDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO) 



class RoleResourceJsonVO : public JsonVO<oatpp::List<RoleResourceInfoDTO::Wrapper>>
{
	DTO_INIT(RoleResourceJsonVO, JsonVO<oatpp::List<RoleResourceInfoDTO::Wrapper>>);

public:
	RoleResourceJsonVO()
	{
		this->data = {};
	}
};





#include OATPP_CODEGEN_END(DTO)

#endif // !_ROLERESOURCEVO_H_
