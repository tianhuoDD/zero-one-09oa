#pragma once
#ifndef _FORM_SERVICE_
#define _FORM_SERVICE_
#include <list>
#include "domain/dto/content/management/GetFormDTO.h"
#include "domain/query/content/management/FormQuery.h"
#include "domain/do/content/management/FormDO.h"
#include "../dao/FormDAO.h"
#include "domain/dto/content/management/ModifyFormDTO.h"


class FormService
{
public:
	// 获取栏目表单列表
	GetFormPageDTO::Wrapper queryForms(const FormQuery::Wrapper& query);

	bool updateData(const ModifyFormDTO::Wrapper& dto);

	bool removeData(string id);
};

#endif // !_FORM_SERVICE_
#pragma once
