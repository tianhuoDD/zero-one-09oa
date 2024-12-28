#pragma once
#ifndef _GETPERSONMEMBER_DAO_
#define _GETPERSONMEMBER_DAO_
#include "BaseDAO.h"
#include"domain/do/get/getpersonmember/GetPersonMemberDO.h"
#include"domain/query/get/getpersonmember/GetPersonMemberQuery.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/getpersonmember/GetPersonMemberDTO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class GetPersonMemberDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const GetPersonMemberQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GetPersonMemberDO> selectWithPage(const GetPersonMemberQuery::Wrapper& query);

	list<GetPersonMemberDTO> selectGroupMemberWithPage(const list<GetPersonMemberDO>& list);

};
#endif // !_SAMPLE_DAO_