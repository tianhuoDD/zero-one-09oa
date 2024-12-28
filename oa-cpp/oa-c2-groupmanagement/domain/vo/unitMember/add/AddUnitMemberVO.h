//
// Created by asd on 2024/10/19.
//

#ifndef ADDUNITMEMBERVO_H
#define ADDUNITMEMBERVO_H

#include "../../../GlobalInclude.h"
#include "domain/dto/unitMember/add/AddUnitMemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddUnitMemberJsonVO : public ListJsonVO<AddUnitMemberRespDTO::Wrapper> {
	DTO_INIT(AddUnitMemberJsonVO, ListJsonVO<AddUnitMemberRespDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //ADDUNITMEMBERVO_H
