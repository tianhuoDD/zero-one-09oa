#pragma once
#ifndef _GROUP_DAO_
#define _GROUP_DAO_
#include "BaseDAO.h"
#include <domain/do/put/GroupDO.h>
/**
 * ʾ�������ݿ����ʵ��
 */
class GroupDAO : public BaseDAO
{
public:
	//// ͳ����������
	//uint64_t count(const UserQuery::Wrapper& query);
	// �޸�����
	int update(const GroupDO& uObj);

};
#endif // !_GROUP_DAO_