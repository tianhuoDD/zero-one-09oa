#pragma once
 /*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 25�� ������ 10:30:13 CST
*/
#ifndef _IDMEMBERDTO_H_
#define _IDMEMBERDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class IDmemberDTO : public oatpp::DTO
{
	DTO_INIT(IDmemberDTO, DTO);
	//��Ա����
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("organization.group.field.xname"),false, ZH_WORDS_GETTER("organization.group.field.yname.manyy"));
	//�㼶����
	API_DTO_FIELD(String, xunitLevelName, ZH_WORDS_GETTER("organization.group.field.xunitLevelName"),false, ZH_WORDS_GETTER("organization.group.field.yname.qqcy"));

	//GROUP_XID	xidentityList	xorderColumn
	//Ⱥ���ʶ
	//API_DTO_FIELD(String, GROUP_XID, ZH_WORDS_GETTER("organization.group.field.group_xid"), false, "family");
	//��ݳ�Ա��ʶ
	//API_DTO_FIELD(String, xidentityList, ZH_WORDS_GETTER("organization.group.field.xidentityList"), false, "manyy_no");
	//�ڱ��г��ֵ�λ��
	//API_DTO_FIELD(Int32, xorderColumn, ZH_WORDS_GETTER("organization.group.field.xorderColumn"), false, 0);
};

/**
 * ʾ����ҳ�������
 */
class IDmemberPageDTO : public PageDTO<IDmemberDTO::Wrapper>
{
	DTO_INIT(IDmemberPageDTO, PageDTO<IDmemberDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_IDMEMBERDTO_H_