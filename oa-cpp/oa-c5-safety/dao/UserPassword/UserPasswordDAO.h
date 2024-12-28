#pragma once

#include "stdafx.h"
#include "BaseDAO.h"
#include "../../domain/dto/UserPassword/UserPasswordDTO.h"  // ����ƴд����

#ifndef _USERPASSWORD_DAO_
#define _USERPASSWORD_DAO_

/**
 * ���ݿ����ʵ��
 */
class UserPasswordDAO : public BaseDAO
{
public:
    // �޸��û�������ص���������
    bool modifyUserPasswordSettings(const UserPasswordDTO::Wrapper& dto);
};

#endif // _USERPASSWORD_DAO_
