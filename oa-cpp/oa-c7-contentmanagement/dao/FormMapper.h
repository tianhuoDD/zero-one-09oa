#pragma once
#ifndef _FORM_MAPPER_
#define _FORM_MAPPER_

#include "Mapper.h"
#include "../domain/do/content/management/FormDO.h"

class FormMapper : public Mapper<FormDO>
{
public:
	FormDO mapper(ResultSet* resultSet) const override
	{
		FormDO data;
		data.setId(resultSet->getString(1));
		data.setUpdateTime(resultSet->getString(2));
		data.setAlias(resultSet->getString(3));
		data.setDescription(resultSet->getString(4));
		return data;
	}
};

#endif // !_FORM_MAPPER_