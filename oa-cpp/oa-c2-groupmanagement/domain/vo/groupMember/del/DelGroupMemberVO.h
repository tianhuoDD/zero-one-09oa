//
// Created by asd on 2024/10/20.
//

#ifndef DELGROUPMEMBERVO_H
#define DELGROUPMEMBERVO_H

#include "../../../GlobalInclude.h"
#include "domain/dto/groupMember/del/DelGroupMemberDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class DelGroupMemberJsonVO : public JsonVO<DelGroupMemberDTO::Wrapper> {
	DTO_INIT(DelGroupMemberJsonVO, JsonVO<DelGroupMemberDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //DELGROUPMEMBERVO_H
