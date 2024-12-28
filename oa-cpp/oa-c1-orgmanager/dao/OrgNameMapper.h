#pragma 
#ifndef _ORGNAMEMAPPER_H_
#define _ORGNAMEMAPPER_H_
#include "Mapper.h"
#include "../domain/do/OrgNameTreeDO.h"

class OrgNameMapper : public Mapper<OrgNameTreeDO>
{
public:
	OrgNameTreeDO mapper(ResultSet* resultSet) const override
	{
		OrgNameTreeDO data;
		data.setXid(resultSet->getString(1));
		data.setXname(resultSet->getString(2));
		data.setXunique(resultSet->getString(3));
		data.setXlevel(resultSet->getInt(4));
		data.setXlevelname(resultSet->getString(5));
		data.setXsuperior(resultSet->getString(6));
		data.setXlevelOrderNumber(resultSet->getString(7));
		
		return data;
	}
	
};

#endif // !_ORGNAMEMAPPER_H_