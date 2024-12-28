#ifndef _QueryPerson_VO_
#define _QueryPerson_VO_

#include "../../../GlobalInclude.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/personlist/PersonListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PersonListPageJsonVO : public JsonVO<PersonListPageDTO::Wrapper> {
	DTO_INIT(PersonListPageJsonVO, JsonVO<PersonListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_QueryPerson_VO_