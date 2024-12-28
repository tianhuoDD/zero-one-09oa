#pragma once
#ifndef _GETROLEDTO_H_
#define _GETROLEDTO_H_

#include "../../../../GlobalInclude.h" //����Ŀ¼

#include OATPP_CODEGEN_BEGIN(DTO)//���DTO�ඨ��ĺ�

//�ܱ��޸ĵĶ���
class GetRoleDTO :public oatpp::DTO
{
	DTO_INIT(GetRoleDTO, DTO);

	// ��ɫ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.name");
	}
	// Ψһ����
	DTO_FIELD(String, key);
	DTO_FIELD_INFO(key) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.key");
	}
	// ��ɫ����
	DTO_FIELD(String, refer);
	DTO_FIELD_INFO(refer) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.refer");
	}
};

class GetRolePageDTO : public PageDTO<GetRoleDTO::Wrapper>
{
	DTO_INIT(GetRolePageDTO, PageDTO<GetRoleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETROLEDTO_H_
