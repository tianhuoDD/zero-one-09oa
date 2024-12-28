#ifndef _QUERY_PERSON_DTO
#define _QUERY_PERSON_DTO
#include "../../../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PersonListDTO : public oatpp::DTO
{
	DTO_INIT(PersonListDTO, DTO);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = "name";
	}
	// 工号
	DTO_FIELD(String, employee);
	DTO_FIELD_INFO(employee) {
		info->description = "employee";
	}
	// 电话
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = "phone";
	}
	// 邮箱
	DTO_FIELD(String, mailbox);
	DTO_FIELD_INFO(mailbox) {
		info->description = "mailbox";
	}
	DTO_FIELD(String, xpersonList);
	DTO_FIELD_INFO(xpersonList) {
		info->description = "xpersonList";
	}

};

/**
 * 示例分页传输对象
 */
class PersonListPageDTO : public PageDTO<PersonListDTO::Wrapper>
{
	DTO_INIT(PersonListPageDTO, PageDTO<PersonListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUERY_PERSON_DTO