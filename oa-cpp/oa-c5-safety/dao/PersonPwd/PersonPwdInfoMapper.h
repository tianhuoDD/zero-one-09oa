#pragma once
#ifndef _PERSONPWD_MAPPER_
#define _PERSONPWD_MAPPER_
#include "Mapper.h"
#include "../../domain/do/PersonPwd/PersonPwdInfoDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class PersonPwdInfoMapper : public Mapper<PersonPwdInfoDO>
{
public:
	PersonPwdInfoDO mapper(ResultSet* resultSet) const override
	{
		PersonPwdInfoDO data;
		data.setId(resultSet->getString(1));
		data.setPassword(resultSet->getString(2));
		return data;
	}
};
#endif
