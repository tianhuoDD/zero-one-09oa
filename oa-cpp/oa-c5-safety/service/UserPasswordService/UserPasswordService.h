#pragma once

#ifndef _USERPASSWORD_SERVICE_
#define _USERPASSWORD_SERVICE_
#include "domain/dto/UserPassword/UserPasswordDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class UserPasswordService
{
public:
    bool modifyUserPasswordSettings(const UserPasswordDTO::Wrapper& dto);
};


#endif