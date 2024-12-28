#pragma once
#ifndef _FORMNAME_MAPPER_
#define _FORMNAME_MAPPER_

#include "Mapper.h"
#include "domain/do/form/FormNameDO.h"

/**
 * ±Ìµ•√˚≥∆∆•≈‰”≥…‰
 */
class FormNameMapper : public Mapper<FormNameDO> {
public:
	FormNameDO mapper(ResultSet* resultSet) const override {
		FormNameDO data;
		data.setName(resultSet->getString("xname"));
		return data;
	}
};

#endif // !_FORMNAME_MAPPER_
