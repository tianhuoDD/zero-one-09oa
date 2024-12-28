#pragma once
#ifndef _PERSONPWD_DAO_
#define _PERSONPWD_DAO_
#include "BaseDAO.h"
#include "domain/dto/PersonPwd/PersonPwdInfoDTO.h"
#include "domain/do/PersonPwd/PersonPwdInfoDO.h"

/**
 * 示例表数据库操作实现
 */
class PersonPwdInfoDAO : public BaseDAO
{
public:
	// 通过id查询数据
	list<PersonPwdInfoDO> selectById(const string& id);
	
};
#endif

