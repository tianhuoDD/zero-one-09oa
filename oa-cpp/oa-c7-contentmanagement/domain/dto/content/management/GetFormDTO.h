#pragma once
#ifndef _GETFORM_DTO_
#define _GETFORM_DTO_
#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
	��ȡ��Ŀ���б������
	author��toki
*/
class GetFormDTO : public oatpp::DTO {
	DTO_INIT(GetFormDTO, DTO);

	//��id
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("content.management.field.xid"));
	// ����ʱ�� (ͨ����ϵͳ���ã�����Ҫ����)
	API_DTO_FIELD_DEFAULT(String, xupdateTime, ZH_WORDS_GETTER("content.management.field.xupdateTime"));
	// ���� (���޸�)
	API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("content.management.field.xdescription"));
	// ���� (���޸�)
	API_DTO_FIELD_DEFAULT(String, xalias, ZH_WORDS_GETTER("content.management.field.xalias"));
	// Ӧ��ID (���޸�)
	API_DTO_FIELD_DEFAULT(String, xappId, ZH_WORDS_GETTER("content.management.field.xappId"));

};


class GetFormPageDTO : public PageDTO<GetFormDTO::Wrapper>
{
	DTO_INIT(GetFormPageDTO, PageDTO<GetFormDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif