#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 25日 星期五 19:20:15 CST
*/
#ifndef _ADDPERSON_DTO_
#define _ADDPERSON_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class AddPersonDTO : public oatpp::DTO
{
	DTO_INIT(AddPersonDTO, DTO);
	// 群组标识
	DTO_FIELD(String, GROUP_XID);
	DTO_FIELD_INFO(GROUP_XID) {
		info->description = ZH_WORDS_GETTER("organization.group.field.group_xid");
	}
	// 个人成员标识
	DTO_FIELD(String, xpersonList);
	DTO_FIELD_INFO(xpersonList) {
		info->description = ZH_WORDS_GETTER("organization.group.field.xpersonList");
	}
	// 在表中出现的位置
	DTO_FIELD(Int32, xorderColumn);
	DTO_FIELD_INFO(xorderColumn) {
		info->description = ZH_WORDS_GETTER("organization.group.field.xorderColumn");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDPERSON_DTO_