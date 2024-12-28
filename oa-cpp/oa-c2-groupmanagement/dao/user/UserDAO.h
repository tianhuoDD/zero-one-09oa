#pragma once
#ifndef _USER_DAO_
#define _USER_DAO_
#include "BaseDAO.h"
#include <domain/do/get/UserDO.h>
#include "domain/query/user/UserQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class UserDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const UserQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<UserDO> selectWithPage(const UserQuery::Wrapper& query);
	//// ͨ��������ѯ����
	//list<UserDO> selectByName(const string& name);
	// �޸�����
	/*int update(const UserDO& uObj);*/

};
#endif // !_USER_DAO_