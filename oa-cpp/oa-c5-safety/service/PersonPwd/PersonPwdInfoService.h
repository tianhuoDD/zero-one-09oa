#pragma once
#ifndef _PERSONPWD_SERVICE_
#define _PERSONPWD_SERVICE_
#include <list>
#include "domain/vo/PersonPwd/PersonPwdInfoVO.h"
#include "domain/dto/PersonPwd/PersonPwdInfoDTO.h"
#include"domain/vo/BaseJsonVO.h"
class PersonPwdInfoService
{
public:
	// ͨ���û�����ѯ����
	PersonPwdInfoDTO::Wrapper ListAll(const String& id);
};
#endif