#include "stdafx.h"
#include "PersonPwdInfoDAO.h"
#include "PersonPwdInfoMapper.h"
#include"domain/do/PersonPwd/PersonPwdInfoDO.h"
#include <sstream>


list<PersonPwdInfoDO> PersonPwdInfoDAO::selectById(const string & id)
{
	string sql = "SELECT id,password FROM safety-pwd WHERE `id` = `?`";
	PersonPwdInfoMapper mapper;
	return sqlSession->executeQuery<PersonPwdInfoDO, PersonPwdInfoMapper>(sql, mapper, "%s", id);
}