#include "stdafx.h"
#include "UserPasswordService.h"
#include "../../dao/UserPassword/UserPasswordDAO.h"

// �޸��û�������ص���������
bool UserPasswordService::modifyUserPasswordSettings(const UserPasswordDTO::Wrapper& dto)
{
    UserPasswordDAO dao;
    return dao.modifyUserPasswordSettings(dto) == 1;
}
