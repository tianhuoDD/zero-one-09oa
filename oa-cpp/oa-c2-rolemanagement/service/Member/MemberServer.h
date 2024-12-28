#pragma once
#ifndef _PERSONINFO_H_
#define _PERSONINFO_H_
#include <list>
#include "domain/vo/add_del_PersonMember/MemberVO.h"
#include "domain/query/Member/MemberQuery.h"
#include "domain/dto/add_del_PersonMember/MemberDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class MemberService
{
public:
	// ��������
	uint64_t saveData(const MemberDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_PERSONINFO_H_
