#pragma once
#ifndef _PERSONINFO_H_
#define _PERSONINFO_H_
#include <list>
#include "domain/vo/add_del_PersonMember/MemberVO.h"
#include "domain/query/Member/MemberQuery.h"
#include "domain/dto/add_del_PersonMember/MemberDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class MemberService
{
public:
	// 保存数据
	uint64_t saveData(const MemberDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_PERSONINFO_H_
