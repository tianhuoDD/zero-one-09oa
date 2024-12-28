#pragma once

#ifndef _MODIFY_PERSONAL_IDENTITYDTO_
#define _MODIFY_PERSONAL_IDENTITYDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 示例传输对象
 */
class modify_personal_identityDTO : public oatpp::DTO
{
	DTO_INIT(modify_personal_identityDTO, DTO);
	// 唯一编号
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("sample.modifyidentity.xid");
	}
	// 身份名称
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("sample.modifyidentity.xname");
	}
	// 主身份
	DTO_FIELD(Boolean, xmajor);
	DTO_FIELD_INFO(xmajor) {
		info->description = ZH_WORDS_GETTER("sample.modifyidentity.xmajor");
	}
};

/**
 * 示例分页传输对象
 */
class modify_personalidentityPageDTO : public PageDTO<modify_personal_identityDTO::Wrapper>
{
	DTO_INIT(modify_personalidentityPageDTO, PageDTO<modify_personal_identityDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MODIFY_PERSONAL_identityDTO_