#pragma once

#ifndef _FORMTEMPLATEQUERY_H_
#define _FORMTEMPLATEQUERY_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FormTemplateQuery : public PageQuery
{
	DTO_INIT(FormTemplateQuery, PageQuery);

	API_DTO_FIELD_DEFAULT(String,id, ZH_WORDS_GETTER("form.field.id"))

	API_DTO_FIELD_DEFAULT(String, templateName, ZH_WORDS_GETTER("form.field.templateName"));

	API_DTO_FIELD_DEFAULT(String, category, ZH_WORDS_GETTER("form.field.category"));
};

#include OATPP_CODEGEN_END(DTO)

#endif