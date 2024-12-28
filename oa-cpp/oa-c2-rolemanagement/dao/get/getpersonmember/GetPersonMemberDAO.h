#pragma once
#ifndef _GETPERSONMEMBER_DAO_
#define _GETPERSONMEMBER_DAO_
#include "BaseDAO.h"
#include"domain/do/get/getpersonmember/GetPersonMemberDO.h"
#include"domain/query/get/getpersonmember/GetPersonMemberQuery.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/getpersonmember/GetPersonMemberDTO.h"

/**
 * 示例表数据库操作实现
 */
class GetPersonMemberDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const GetPersonMemberQuery::Wrapper& query);
	// 分页查询数据
	list<GetPersonMemberDO> selectWithPage(const GetPersonMemberQuery::Wrapper& query);

	list<GetPersonMemberDTO> selectGroupMemberWithPage(const list<GetPersonMemberDO>& list);

};
#endif // !_SAMPLE_DAO_