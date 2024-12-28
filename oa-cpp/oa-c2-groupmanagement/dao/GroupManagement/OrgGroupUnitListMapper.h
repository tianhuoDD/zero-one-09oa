//
// Created by asd on 2024/10/26.
//

#ifndef ORGGROUPUNITLISTMAPPER_H
#define ORGGROUPUNITLISTMAPPER_H
#include <Mapper.h>

class OrgGroupUnitListMapper : public Mapper<oatpp::String> {
public:
	oatpp::String mapper(ResultSet* resultSet) const override{
		oatpp::String data = resultSet->getString(1).c_str();

		return data;
	}
};

#endif //ORGGROUPUNITLISTMAPPER_H
