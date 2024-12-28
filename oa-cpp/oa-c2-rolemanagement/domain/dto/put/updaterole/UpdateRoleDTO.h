#ifndef _UPDATE_ROLE_DTO
#define _UPDATE_ROLE_DTO
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class UpdateRoleDTO : public oatpp::DTO
{
	DTO_INIT(UpdateRoleDTO, DTO);
	// 修改前唯一编码
	DTO_FIELD(String, last_xunique);
	DTO_FIELD_INFO(last_xunique) {
		info->description = "last_xunique";
	}
	// 修改后姓名
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = "name";
	}
	// 修改后唯一编码
	DTO_FIELD(String, newxunique);
	DTO_FIELD_INFO(newxunique) {
		info->description = "newunique";
	}
	// 修改后描述
	DTO_FIELD(String, xdescription);
	DTO_FIELD_INFO(xdescription) {
		info->description = "description";
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UPDATE_ROLE_DTO