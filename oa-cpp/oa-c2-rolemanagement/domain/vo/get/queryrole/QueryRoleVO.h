#pragma once
#ifndef _GETROLELIST_VO_
#define _GETROLELIST_VO_

#include "../../../GlobalInclude.h"
#include "../../../dto/rolemanagement/RoleManagementDTO/get/queryrole/QueryRoleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class QueryRoleJsonVO : public JsonVO<QueryRoleDTO::Wrapper> {
	DTO_INIT(QueryRoleJsonVO, JsonVO<QueryRoleDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class QueryRolePageJsonVO : public JsonVO<QueryRolePageDTO::Wrapper> {
	DTO_INIT(QueryRolePageJsonVO, JsonVO<QueryRolePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ROLELIST_VO_
