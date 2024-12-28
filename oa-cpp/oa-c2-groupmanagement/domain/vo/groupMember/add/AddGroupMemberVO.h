//
// Created by asd on 2024/10/19.
//

#ifndef ADDGROUPMEMBERVO_H
#define ADDGROUPMEMBERVO_H

#include "../../../GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/groupMember/add/AddGroupMemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddGroupMemberJsonVO : public ListJsonVO<AddGroupMemberRespDTO::Wrapper> {
	DTO_INIT( AddGroupMemberJsonVO, ListJsonVO<AddGroupMemberRespDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //ADDGROUPMEMBERVO_H
