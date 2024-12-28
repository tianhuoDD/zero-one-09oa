#pragma once
#ifndef _APPLICATIONTYPES_MAPPER_
#define _APPLICATIONTYPES_MAPPER_

#include "Mapper.h"
#include "domain/do/application/ApplicationTypesDO.h"

class ApplicationTypesMapper : public Mapper<ApplicationTypesDO> {
public:
	ApplicationTypesDO mapper(ResultSet* res) const override {
		ApplicationTypesDO obj;
		obj.setXapplicationCategory(res->getString("xapplicationCategory"));
		obj.setXcount(res->getInt("xcount"));
		return obj;
	}
};
#endif // !_APPLICATIONTYPES_MAPPER_
