#pragma once
#ifndef _GETPERSONMEMBER_DTO_
#define _GETPERSONMEMBER_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class GetPersonMemberDTO : public oatpp::DTO
{
	DTO_INIT(GetPersonMemberDTO, DTO);

	DTO_FIELD(String, xgroupList);
	DTO_FIELD_INFO(xgroupList) {
		info->description = "xgroupList";
	}
	// ��Աid
	DTO_FIELD(String, role_xid);
	DTO_FIELD_INFO(role_xid) {
		info->description = ZH_WORDS_GETTER("PersonMember.field.ROLE_XID");
	}
	// ����id
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("PersonMember.field.xname");
	}
	// ˳��
	DTO_FIELD(String, xdescription);
	DTO_FIELD_INFO(xdescription) {
		info->description = ZH_WORDS_GETTER("PersonMember.field.xdescription");
	}	// ˳��
	DTO_FIELD(String, xdistinguishedName);
	DTO_FIELD_INFO(xdistinguishedName) {
		info->description = ZH_WORDS_GETTER("PersonMember.field.xdistinguishedName");
	}
public:
	GetPersonMemberDTO(){}
	GetPersonMemberDTO(String role_xid, String xname, String xdescription, String xdistinguishedName)
	{
		this->role_xid = role_xid;
		this->xname = xname;
		this->xdescription = xdescription;
		this->xdescription = xdistinguishedName;
	}
};

/**
 * ʾ����ҳ�������
 */
class GetPersonMemberPageDTO : public PageDTO<GetPersonMemberDTO::Wrapper>
{
	DTO_INIT(GetPersonMemberPageDTO, PageDTO<GetPersonMemberDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETPERSONMEMBER_DTO_