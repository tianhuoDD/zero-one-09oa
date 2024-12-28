#include "stdafx.h"
#include "RoomPosDAO.h"
#include "domain/do/room-new/RoomPosDO.h"



  
//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}

std::string getCurrentTimeString();

int RoomPosDAO::updateById(const RoomBuildingDO & uobj) {
	string sql = "UPDATE `mt_building` SET `xupdateTime`=?,`xname`=?,`xpinyin`=?,`xpinyinInitial`=?,`xaddress`=? WHERE `xid`=?";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s",	\
	getCurrentTimeString(),uobj.getXname(),uobj.getXpinyin(),uobj.getXpinyinintial(),uobj.getXaddress(),uobj.getXid());

}

int RoomPosDAO::updateByName(const std::string& xname)
{
	string sql = "UPDATE `mt_building` SET `xupdateTime`=?,`xname`=?,`xpinyin`=?,`xpinyinInitial`=? WHERE `xname`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s", \
	getCurrentTimeString(),	xname,xname, xname);
}

int RoomPosDAO::deleteById(const std::string& id)
{
	string sql = "DELETE FROM `mt_building` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
	
}

int RoomPosDAO::deleteByName(const string& name)
{
	string sql = "DELETE FROM `mt_building` WHERE `xname`=?";
	return sqlSession->executeUpdate(sql, "%s", name);
}


std::string getCurrentTimeString()
{
	std::time_t currentTime = std::time(nullptr);
	std::tm* localTime = std::localtime(&currentTime);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
	return std::string(buffer);
}


