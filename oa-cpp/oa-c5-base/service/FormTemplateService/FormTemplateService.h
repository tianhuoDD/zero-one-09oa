#pragma once
#include "domain/vo/FormTemplateVO.h"
#include "domain/query/FormTemplateQuery.h"
#include "domain/dto/FormTemplateDTO.h"
#ifndef _FORMTEMPLATE_SERVICE_
#define _FORMTEMPLATE_SERVICE_

class FormTemplateService
{
public:
	FormTemplatePageDTO::Wrapper listAll(const FormTemplateQuery::Wrapper& query);
};
#endif