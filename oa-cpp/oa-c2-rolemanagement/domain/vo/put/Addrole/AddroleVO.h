#pragma once
#ifndef _ADDROLE_VO_
#define _ADDROLE_VO_

#include "../../../GlobalInclude.h"
#include "../../../dto/rolemanagement/RoleManagementDTO/put/addrole/AddroleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 用于接收客户端的Json对象
 */
class AddroleJsonVO : public JsonVO<AddroleDTO::Wrapper> {
	DTO_INIT(AddroleJsonVO, JsonVO<AddroleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDROLE_VO_
