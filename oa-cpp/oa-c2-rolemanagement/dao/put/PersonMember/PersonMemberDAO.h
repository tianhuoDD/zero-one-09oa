#pragma once
//_PERSONMEMBERDAO_
#ifndef _PERSONMEMBERDAO_
#define _PERSONMEMBERDAO_
#include "BaseDAO.h"
#include "domain/do/put/PersonMember/PersonMemberDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class PersonMemberDAO : public BaseDAO
{
public:
	// ��������
	//uint64_t insert(const PersonMemberDO& iObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);
	std::list<oatpp::String> selectPersonMemberList(const string roleId);
	uint64_t selectMaxXordercolumn(const string roleId, const string dataTableName, const string field);
	uint64_t updatePersonMemberList(const string role_xid, list<oatpp::String>& dataPersonList, std::list<PersonMemberDO>& listData);
	uint64_t insertPersonMemberList(const std::list<PersonMemberDO>& listIobj);
	uint64_t deletePersonMemberList(const string roleId, const string groupId, const uint64_t maxColumn);
	uint64_t deletePersonMemberListOperation(const string role_xid, const std::list<oatpp::String>& xpersonList);
};
#endif // !_PERSONMEMBERDAO_
