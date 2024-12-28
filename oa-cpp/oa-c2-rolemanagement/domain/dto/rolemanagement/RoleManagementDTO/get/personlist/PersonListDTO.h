#ifndef _QUERY_PERSON_DTO
#define _QUERY_PERSON_DTO
#include "../../../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class PersonListDTO : public oatpp::DTO
{
	DTO_INIT(PersonListDTO, DTO);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = "name";
	}
	// ����
	DTO_FIELD(String, employee);
	DTO_FIELD_INFO(employee) {
		info->description = "employee";
	}
	// �绰
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = "phone";
	}
	// ����
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
 * ʾ����ҳ�������
 */
class PersonListPageDTO : public PageDTO<PersonListDTO::Wrapper>
{
	DTO_INIT(PersonListPageDTO, PageDTO<PersonListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUERY_PERSON_DTO