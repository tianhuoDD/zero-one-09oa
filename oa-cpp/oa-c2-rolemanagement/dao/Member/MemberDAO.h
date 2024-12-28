#pragma once
#ifndef _Member_DAO_
#define _Member_DAO_
#include "BaseDAO.h"
#include "domain/do/Member/MemberDo.h"
#include "../../domain/query/Member/MemberQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class MemberDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const MemberDo& iObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_Member_DAO_
