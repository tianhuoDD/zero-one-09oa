#include "stdafx.h"
#include "CalenderDAO.h"
#include <sstream>

//新建日历数据插入的模板
template<typename T>
uint64_t CalenderDAO::executeInsert(const string& table, const string& filed, const T& Obj)
{
	try
	{
		string sql = "INSERT INTO`" + table + "` (`CALENDAR_XID`, `" + filed + "`, `xorderColumn`) VALUES (?, ?, ?)";
		return sqlSession->executeUpdate(sql, "%s%s%i", Obj.getCalenderId(), Obj.getFiled(), Obj.getxOrderColumn());
	}
	catch (const exception& e)
	{
		throw runtime_error("Failed to insert into table " + table + ":" + e.what());
	}
}

uint64_t CalenderDAO::executeCount(const string& table, const string& xid, const string& xidType)
{
	try
	{
		string sql = "SELECT COUNT(" + xidType + ") FROM`" + table + "` WHERE `" + xidType + "`= ? ";
		return sqlSession->executeQueryNumerical(sql, "%s", xid);
	}
	catch (const exception& e)
	{
		throw runtime_error("Failed to count table " + table + ": " + e.what());
	}
}

uint64_t CalenderDAO::executeDelete(const string& table, const string& xid)
{
	try
	{
		string sql = "DELETE FROM `" + table + "` WHERE `CALENDAR_XID`=?";
		if (sqlSession->executeUpdate(sql, "%s", xid) > 0)
			return 1;
		else
			return 0;
	}
	catch (const exception& e)
	{
		throw runtime_error("Failed to delete table " + table + ":" + e.what());
	}
}

uint64_t CalenderDAO::executeCDCombination(string xid)
{
	int ans = 1;  //累计操作结果
	if (executeCount("cal_calendar_manageablepersonlist", xid, "CALENDAR_XID"))
	{
		//删除管理者数据
		ans = executeDelete("cal_calendar_manageablepersonlist", xid);
	}
	if (executeCount("cal_calendar_viewablepersonlist", xid, "CALENDAR_XID"))
	{
		//删除可见范围的人数据
		ans &= executeDelete("cal_calendar_viewablepersonlist", xid);
	}
	if (executeCount("cal_calendar_viewableunitlist", xid, "CALENDAR_XID"))
	{
		//删除可见范围的组织数据
		ans &= executeDelete("cal_calendar_viewableunitlist", xid);
	}
	if (executeCount("cal_calendar_viewablegrouplist", xid, "CALENDAR_XID"))
	{
		//删除可见范围的群组数据
		ans &= executeDelete("cal_calendar_viewablegrouplist", xid);
	}
	if (executeCount("cal_calendar_publishablepersonlist", xid, "CALENDAR_XID"))
	{
		//删除可新建范围的人数据
		ans &= executeDelete("cal_calendar_publishablepersonlist", xid);
	}
	if (executeCount("cal_calendar_publishableunitlist", xid, "CALENDAR_XID"))
	{
		//删除可新建范围的组织数据
		ans &= executeDelete("cal_calendar_publishableunitlist", xid);
	}
	if (executeCount("cal_calendar_publishablegrouplist", xid, "CALENDAR_XID"))
	{
		//删除可新建范围的群组数据
		ans &= executeDelete("cal_calendar_publishablegrouplist", xid);
	}
	return ans;
}
//主数据表的插入
uint64_t CalenderDAO::insert(const cal_calendarDO& iObj)
{
	string sql = "INSERT INTO `cal_calendar` (`xid`, `xcolor`, `xdescription`, `xispublic`, `xname`, `xstatus`, `xtarget`, `xtype`, `xcreateor`, `xcreatetime`, `xupdatetime`, `xsequence`, `xsource`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%s%s%s%s", iObj.getxId(), iObj.getxColor(), iObj.getxDescription(),
		iObj.getxIsPublic(), iObj.getxName(), iObj.getxStatus(), iObj.getxTarget(), iObj.getxType(), iObj.getxCreateor(), iObj.getxCreateTime(), iObj.getxUpdateTime(), iObj.getxSequence(), iObj.getxSource());
}

// 插入管理者数据
uint64_t CalenderDAO::insert(const cal_calendar_manageablepersonlistDO& iObj)
{
	return executeInsert("cal_calendar_manageablepersonlist", "xmanageablepersonlist", iObj);
}

// 插入可见范围的人数据
uint64_t CalenderDAO::insert(const cal_calendar_viewablepersonlistDO& iObj)
{
	return executeInsert("cal_calendar_viewablepersonlist", "xviewablePersonList", iObj);
}

// 插入可见范围的组织数据
uint64_t CalenderDAO::insert(const cal_calendar_viewableunitlistDO& iObj)
{
	return executeInsert("cal_calendar_viewableunitlist", "xviewableUnitList", iObj);
}

// 插入可见范围的群组数据
uint64_t CalenderDAO::insert(const cal_calendar_viewablegrouplistDO& iObj)
{
	return executeInsert("cal_calendar_viewablegrouplist", "xviewableGroupList", iObj);
}

// 插入可新建范围的人数据
uint64_t CalenderDAO::insert(const cal_calendar_publishablepersonlistDO& iObj)
{
	return executeInsert("cal_calendar_publishablepersonlist", "xpublishablePersonList", iObj);
}

// 插入可新建范围的组织数据
uint64_t CalenderDAO::insert(const cal_calendar_publishableunitlistDO& iObj)
{
	return executeInsert("cal_calendar_publishableunitlist", "xpublishableUnitList", iObj);
}

// 插入可新建范围的群组数据
uint64_t CalenderDAO::insert(const cal_calendar_publishablegrouplistDO& iObj)
{
	return executeInsert("cal_calendar_publishablegrouplist", "xpublishableGroupList", iObj);
}

int CalenderDAO::update(const cal_calendarDO& uObj)
{
	if (executeCount("cal_calendar", uObj.getxId(), "xid"))
	{
		string sql = "UPDATE `cal_calendar` SET `xcolor`=?, `xdescription`=?, `xispublic`=?, `xname`=?, `xstatus`=?, `xtarget`=?, `xtype`=? , `xupdatetime`=? WHERE `xid`=?";
		return sqlSession->executeUpdate(sql, "%s%s%i%s%s%s%s%s%s", uObj.getxColor(), uObj.getxDescription(), uObj.getxIsPublic(),
			uObj.getxName(), uObj.getxStatus(), uObj.getxTarget(), uObj.getxType(), uObj.getxUpdateTime(), uObj.getxId());
	}
	return 0;
}

int CalenderDAO::deleteById(string xid)
{
	//删除主数据表数据
	if (executeCount("cal_calendar", xid, "xid"))  //判断是否数据存在
	{
		string sql = "DELETE FROM `cal_calendar` WHERE `xid`= ? ";
		int ans = sqlSession->executeUpdate(sql, "%s", xid);
		return ans & executeCDCombination(xid);
	}
	return 0;
}

int CalenderDAO::deleteById(string xid, int i)
{
	return executeCDCombination(xid);
}