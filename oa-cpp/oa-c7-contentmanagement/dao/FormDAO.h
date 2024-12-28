#pragma once

#ifndef _FORM_DAO_
#define _FORM_DAO_
#include "BaseDAO.h"
#include "../domain/do/content/management/FormDO.h"
#include "../domain/query/content/management/FormQuery.h"

class FormDAO : public BaseDAO
{
public:
	// ͨ����Ŀid��ѯ���б�
	list<FormDO> selectByAppId(const FormQuery::Wrapper& query);
};
#endif // !_FORM_DAO_
