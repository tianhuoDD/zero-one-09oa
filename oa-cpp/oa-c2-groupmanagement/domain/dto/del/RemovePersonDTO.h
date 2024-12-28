#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 26�� ������ 09:37:55 CST
*/
#ifndef _REMOVEPERSON_DTO_
#define _REMOVEPERSON_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class RemovePersonDTO : public oatpp::DTO
{
	DTO_INIT(RemovePersonDTO, DTO);
	// Ⱥ���ʶ
	DTO_FIELD(String, GROUP_XID);
	DTO_FIELD_INFO(GROUP_XID) {
		info->description = ZH_WORDS_GETTER("organization.group.field.group_xid");
	}
	// ���˳�Ա��ʶ
	DTO_FIELD(String, xpersonList);
	DTO_FIELD_INFO(xpersonList) {
		info->description = ZH_WORDS_GETTER("organization.group.field.xpersonList");
	}
	// �ڱ��г��ֵ�λ��
	/*DTO_FIELD(Int32, xorderColumn);
	DTO_FIELD_INFO(xorderColumn) {
		info->description = ZH_WORDS_GETTER("organization.group.field.xorderColumn");
	}*/
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REMOVEPERSON_DTO_