#pragma once
#ifndef _PERSONMEMBER_H_
#define _PERSONMEMBER_H_
#include <list>
#include "domain/dto/rolemanagement/RoleManagementDTO/put/personmember/PersonMemberDTO.h"
#include"domain/do/put/PersonMember/PersonMemberDO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PersonMemberService
{
public:
	// ��������
	uint64_t saveData(const PersonMemberDTO::Wrapper& dto);

	uint64_t removePersonMember(const PersonMemberDTO::Wrapper& xpersonList);
};

#endif // !_PERSONMEMBER_H_