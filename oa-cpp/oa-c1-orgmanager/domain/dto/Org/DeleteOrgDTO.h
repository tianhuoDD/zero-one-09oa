#pragma once
#ifndef _DELETEORGDTO_
#define _DELETEORGDTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//创建组织DTO
class DeleteOrgDTO : public oatpp::DTO
{
	DTO_INIT(DeleteOrgDTO, DTO);
	// 要删除的组织唯一编码列表
	DTO_FIELD(String, xid);

	//描述
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("post.deleteOrg.xid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEORGDTO_