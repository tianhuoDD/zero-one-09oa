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
	// 通过用户名查询密码
	PersonPwdInfoDTO::Wrapper ListAll(const String& id);
};
#endif