#include "stdafx.h"
#include "UserPasswordService.h"
#include "../../dao/UserPassword/UserPasswordDAO.h"

// 修改用户密码相关的所有设置
bool UserPasswordService::modifyUserPasswordSettings(const UserPasswordDTO::Wrapper& dto)
{
    UserPasswordDAO dao;
    return dao.modifyUserPasswordSettings(dto) == 1;
}
