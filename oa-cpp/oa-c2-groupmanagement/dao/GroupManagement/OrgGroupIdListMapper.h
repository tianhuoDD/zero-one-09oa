//
// Created by asd on 2024/10/26.
//

#ifndef ORGGROUPIDLISTMAPPER_H
#define ORGGROUPIDLISTMAPPER_H
#include <Mapper.h>

class OrgGroupIdListMapper : public Mapper<oatpp::String> {
public:
	oatpp::String mapper(ResultSet* resultSet) const override{
		oatpp::String data = resultSet->getString(1).c_str();

		return data;
	}
};

#endif //ORGGROUPIDLISTMAPPER_H
