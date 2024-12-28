#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 23日 星期三 16:40:58 CST

*/
#ifndef _IDMEMBER_QUERY_
#define _IDMEMBER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class IDmemberQuery : public PageQuery
{
	DTO_INIT(IDmemberQuery, PageQuery);
	 //人员名称
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("organization.group.field.xname");
	}
	// 层级名称
	DTO_FIELD(String, xunitLevelName);
	DTO_FIELD_INFO(xunitLevelName) {
		info->description = ZH_WORDS_GETTER("organization.group.field.xunitLevelName");
	}

	////群组标识
	//DTO_FIELD(String, GROUP_XID);
	//DTO_FIELD_INFO(GROUP_XID) {
	//	info->description = ZH_WORDS_GETTER("organization.group.field.group_xid");
	//}
	////身份成员标识
	//DTO_FIELD(String, xidentityList);
	//DTO_FIELD_INFO(xidentityList) {
	//	info->description = ZH_WORDS_GETTER("organization.group.field.xidentity_list");
	//}
	////在表中出现的位置
	//DTO_FIELD(Int32, xorderColumn);
	//DTO_FIELD_INFO(xorderColumn) {
	//	info->description = ZH_WORDS_GETTER("organization.group.field.xorder_column");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_IDMEMBER_QUERY_