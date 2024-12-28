#pragma once
#ifndef _DELETEMENU_MAPPER_
#define _DELETEMENU_MAPPER_

#include "Mapper.h"

#include "../../../domain/do/Function-permissions/Org_role_menulistDO.h"
/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class DeletemenuMapper : public Mapper<Org_role_menulistDO>
{
public:
	Org_role_menulistDO mapper(ResultSet* resultSet) const override
	{
		Org_role_menulistDO data;
		data.setrole_Id(resultSet->getString(1));
		data.setMenulist(resultSet->getString(2));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_