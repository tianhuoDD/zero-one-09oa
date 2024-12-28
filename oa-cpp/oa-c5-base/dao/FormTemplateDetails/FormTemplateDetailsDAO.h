#pragma once
#ifndef _FORMTEMPLATEDETAILS_DAO_
#define _FORMTEMPLATEDETAILS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/formTemplateBuiltDO.h"
#include "../../domain/query/FormTemplateQuery.h"

class FormTemplateDetailsDAO :public BaseDAO
{
public:
	list<formTemplateBuiltDO> selectInfoById(const char* xid);
	list<formTemplateBuiltDO> selectcategoryAndnumByApp(const char* xid);
};
#endif