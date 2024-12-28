#pragma once

#ifndef _FORM_QUERY_
#define _FORM_QUERY_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ��Ŀ���б��ѯ����
 */
class FormQuery : public PageQuery
{
	DTO_INIT(FormQuery, PageQuery);
	// xappId
	API_DTO_FIELD_DEFAULT(String, xappId, ZH_WORDS_GETTER("content.management.field.xappId"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FORM_QUERY_