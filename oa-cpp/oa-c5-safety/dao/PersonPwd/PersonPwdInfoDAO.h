#pragma once
#ifndef _PERSONPWD_DAO_
#define _PERSONPWD_DAO_
#include "BaseDAO.h"
#include "domain/dto/PersonPwd/PersonPwdInfoDTO.h"
#include "domain/do/PersonPwd/PersonPwdInfoDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class PersonPwdInfoDAO : public BaseDAO
{
public:
	// ͨ��id��ѯ����
	list<PersonPwdInfoDO> selectById(const string& id);
	
};
#endif

