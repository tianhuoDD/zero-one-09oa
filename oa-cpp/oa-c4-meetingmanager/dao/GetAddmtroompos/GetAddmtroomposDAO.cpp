#include "stdafx.h"
#include "GetAddmtroomposDAO.h"
#include "GetAddmtroomposMapper.h"
#include <sstream>
#include <SnowFlake.h>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->xname) { \
	sql << " AND `xname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xname.getValue("")); \
}
std::string getCurrentTime();
uint64_t GetAddmtroomposDAO::count(const GetmtroomposQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `mt_building`";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<GetAddmtroomposDO> GetAddmtroomposDAO::selectWithPage(const GetmtroomposQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `xid`,`xaddress`,`xname` FROM `mt_building`";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetAddmtroomposMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GetAddmtroomposDO, GetAddmtroomposMapper>(sqlStr, mapper, params);
}

uint64_t GetAddmtroomposDAO::insert(const GetAddmtroomposDO& iObj)
{
	string sql = "INSERT INTO `mt_building` (`xid`,`xcreateTime`,`xupdateTime`,`xaddress`,`xname`,`xpinyin`,`xpinyinInitial`) VALUES (?,?,?,?,?,?,?)";
	SnowFlake sf(4, 1);
	string id = to_string(sf.nextId());
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", id, getCurrentTime(), getCurrentTime(), iObj.getXaddress(), iObj.getXname(), iObj.getXpinyin(), iObj.getXpinyinInitial());
}

//int GetAddmtroomposDAO::update(const GetAddmtroomposDO& uObj)
//{
//	string sql = "UPDATE `sample` SET `xname`=?, `xpinyin`=?, `xpinyinInitial`=? WHERE `xid`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getXname(), uObj.getXname(), uObj.getXname(), uObj.getXid());
//}

std::string getCurrentTime()
{
	std::time_t currentTime = std::time(nullptr);
	std::tm* localTime = std::localtime(&currentTime);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
	return std::string(buffer);
}