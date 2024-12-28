//
// Created by asd on 2024/10/20.
//

#ifndef DELUNITMEMBERVO_H
#define DELUNITMEMBERVO_H

#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class DelGroupMemberJsonVO : public JsonVO<DelUnitMemberDTO::Wrapper> {
	DTO_INIT(DelGroupMemberJsonVO, JsonVO<DelUnitMemberDTO::Wrapper> );
};

#endif //DELUNITMEMBERVO_H
