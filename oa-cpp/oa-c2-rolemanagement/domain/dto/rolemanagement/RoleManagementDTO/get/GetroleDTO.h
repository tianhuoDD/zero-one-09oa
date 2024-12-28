#pragma once
#ifndef _GETROLEDTO_H_
#define _GETROLEDTO_H_

#include "../../../../GlobalInclude.h" //二层目录

#include OATPP_CODEGEN_BEGIN(DTO)//标记DTO类定义的宏

//能被修改的东西
class GetRoleDTO :public oatpp::DTO
{
	DTO_INIT(GetRoleDTO, DTO);

	// 角色名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.name");
	}
	// 唯一编码
	DTO_FIELD(String, key);
	DTO_FIELD_INFO(key) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.key");
	}
	// 角色描述
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
