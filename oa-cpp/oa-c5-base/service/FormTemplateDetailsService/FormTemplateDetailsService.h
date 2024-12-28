#pragma once
#ifndef _FORMTEMPLATEDETAILS_SERVICE_
#define _FORMTEMPLATEDETAILS_SERVICE_
#include <list>
#include "../../domain/vo/FormTemplateDetailsVO.h"
#include "../../domain/dto/FormTemplateDetailsDTO.h"
#include "../../domain/query/FormTemplateQuery.h"
#include "../../domain/dto/FormTemplateCategoryDTO.h"

class FormTemplateDetailsService
{
public:
	FormTemplateDetailsDTO::Wrapper listFormInfo(const char* xid);
	oatpp::List<FormTemplateCategoryDTO::Wrapper> listCategory(const char* xid);
};


#endif