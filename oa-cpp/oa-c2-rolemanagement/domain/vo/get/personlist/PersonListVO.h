#ifndef _QueryPerson_VO_
#define _QueryPerson_VO_

#include "../../../GlobalInclude.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/personlist/PersonListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PersonListPageJsonVO : public JsonVO<PersonListPageDTO::Wrapper> {
	DTO_INIT(PersonListPageJsonVO, JsonVO<PersonListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_QueryPerson_VO_