#pragma once
#ifndef _GETPERSONMEMBER_SERVICE_
#define _GETPERSONMEMBER_SERVICE_
#include <list>
#include"domain/query/get/getpersonmember/GetPersonMemberQuery.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/getpersonmember/GetPersonMemberDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GetPersonMemberService
{
public:
	// ��ҳ��ѯ��������
	GetPersonMemberPageDTO::Wrapper listAll(const GetPersonMemberQuery::Wrapper& query);
};

#endif // !_GETPERSONMEMBER_SERVICE_