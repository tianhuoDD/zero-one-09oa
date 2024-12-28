#pragma once

#include "stdafx.h"
#include "BaseDAO.h"
#include "../../domain/dto/UserPassword/UserPasswordDTO.h"  // 纠正拼写错误

#ifndef _USERPASSWORD_DAO_
#define _USERPASSWORD_DAO_

/**
 * 数据库操作实现
 */
class UserPasswordDAO : public BaseDAO
{
public:
    // 修改用户密码相关的所有设置
    bool modifyUserPasswordSettings(const UserPasswordDTO::Wrapper& dto);
};

#endif // _USERPASSWORD_DAO_
