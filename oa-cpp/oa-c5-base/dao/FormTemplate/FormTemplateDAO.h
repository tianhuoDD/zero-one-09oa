#pragma once
#ifndef _FORMTEMPLATE_DAO_
#define _FORMTEMPLATE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/formTemplateBuiltDO.h"
#include "../../domain/query/FormTemplateQuery.h"

class FormTemlplateDAO : public BaseDAO
{
public:
	uint64_t count(const FormTemplateQuery::Wrapper& query);
	list<formTemplateBuiltDO> selectWithPage(const FormTemplateQuery::Wrapper& query);
};
#endif   