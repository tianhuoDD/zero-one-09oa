#pragma once

#ifndef _USERPASSWORD_SERVICE_
#define _USERPASSWORD_SERVICE_
#include "domain/dto/UserPassword/UserPasswordDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class UserPasswordService
{
public:
    bool modifyUserPasswordSettings(const UserPasswordDTO::Wrapper& dto);
};


#endif