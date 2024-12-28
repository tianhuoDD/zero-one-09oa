#pragma once
#ifndef _PERSONMEMBERMAPPER_H_
#define _PERSONMEMBERMAPPER_H_

#include "Mapper.h"
#include "domain/do/put/PersonMember/PersonMemberDO.h"

class PersonMemberMapper :public Mapper<oatpp::String>
{
public:
	oatpp::String mapper(ResultSet* resultSet) const override
	{

		oatpp::String data = resultSet->getString(1).c_str();
		return data;
	}
};



#endif // !_PERSONMEMBERMAPPER_H_#pragma once
