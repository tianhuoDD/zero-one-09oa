#pragma once
#ifndef _GETROLELIST_VO_
#define _GETROLELIST_VO_

#include "../../../GlobalInclude.h"
#include "../../../dto/rolemanagement/RoleManagementDTO/get/queryrole/QueryRoleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class QueryRoleJsonVO : public JsonVO<QueryRoleDTO::Wrapper> {
	DTO_INIT(QueryRoleJsonVO, JsonVO<QueryRoleDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class QueryRolePageJsonVO : public JsonVO<QueryRolePageDTO::Wrapper> {
	DTO_INIT(QueryRolePageJsonVO, JsonVO<QueryRolePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ROLELIST_VO_
