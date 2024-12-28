#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 23�� ������ 16:40:58 CST

*/
#ifndef _IDMEMBER_QUERY_
#define _IDMEMBER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class IDmemberQuery : public PageQuery
{
	DTO_INIT(IDmemberQuery, PageQuery);
	 //��Ա����
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("organization.group.field.xname");
	}
	// �㼶����
	DTO_FIELD(String, xunitLevelName);
	DTO_FIELD_INFO(xunitLevelName) {
		info->description = ZH_WORDS_GETTER("organization.group.field.xunitLevelName");
	}

	////Ⱥ���ʶ
	//DTO_FIELD(String, GROUP_XID);
	//DTO_FIELD_INFO(GROUP_XID) {
	//	info->description = ZH_WORDS_GETTER("organization.group.field.group_xid");
	//}
	////��ݳ�Ա��ʶ
	//DTO_FIELD(String, xidentityList);
	//DTO_FIELD_INFO(xidentityList) {
	//	info->description = ZH_WORDS_GETTER("organization.group.field.xidentity_list");
	//}
	////�ڱ��г��ֵ�λ��
	//DTO_FIELD(Int32, xorderColumn);
	//DTO_FIELD_INFO(xorderColumn) {
	//	info->description = ZH_WORDS_GETTER("organization.group.field.xorder_column");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_IDMEMBER_QUERY_