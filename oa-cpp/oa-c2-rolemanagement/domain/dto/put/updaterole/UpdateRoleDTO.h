#ifndef _UPDATE_ROLE_DTO
#define _UPDATE_ROLE_DTO
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class UpdateRoleDTO : public oatpp::DTO
{
	DTO_INIT(UpdateRoleDTO, DTO);
	// �޸�ǰΨһ����
	DTO_FIELD(String, last_xunique);
	DTO_FIELD_INFO(last_xunique) {
		info->description = "last_xunique";
	}
	// �޸ĺ�����
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = "name";
	}
	// �޸ĺ�Ψһ����
	DTO_FIELD(String, newxunique);
	DTO_FIELD_INFO(newxunique) {
		info->description = "newunique";
	}
	// �޸ĺ�����
	DTO_FIELD(String, xdescription);
	DTO_FIELD_INFO(xdescription) {
		info->description = "description";
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UPDATE_ROLE_DTO