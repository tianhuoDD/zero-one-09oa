#include "stdafx.h"
#include "CalenderDAO.h"
#include <sstream>

//�½��������ݲ����ģ��
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
	int ans = 1;  //�ۼƲ������
	if (executeCount("cal_calendar_manageablepersonlist", xid, "CALENDAR_XID"))
	{
		//ɾ������������
		ans = executeDelete("cal_calendar_manageablepersonlist", xid);
	}
	if (executeCount("cal_calendar_viewablepersonlist", xid, "CALENDAR_XID"))
	{
		//ɾ���ɼ���Χ��������
		ans &= executeDelete("cal_calendar_viewablepersonlist", xid);
	}
	if (executeCount("cal_calendar_viewableunitlist", xid, "CALENDAR_XID"))
	{
		//ɾ���ɼ���Χ����֯����
		ans &= executeDelete("cal_calendar_viewableunitlist", xid);
	}
	if (executeCount("cal_calendar_viewablegrouplist", xid, "CALENDAR_XID"))
	{
		//ɾ���ɼ���Χ��Ⱥ������
		ans &= executeDelete("cal_calendar_viewablegrouplist", xid);
	}
	if (executeCount("cal_calendar_publishablepersonlist", xid, "CALENDAR_XID"))
	{
		//ɾ�����½���Χ��������
		ans &= executeDelete("cal_calendar_publishablepersonlist", xid);
	}
	if (executeCount("cal_calendar_publishableunitlist", xid, "CALENDAR_XID"))
	{
		//ɾ�����½���Χ����֯����
		ans &= executeDelete("cal_calendar_publishableunitlist", xid);
	}
	if (executeCount("cal_calendar_publishablegrouplist", xid, "CALENDAR_XID"))
	{
		//ɾ�����½���Χ��Ⱥ������
		ans &= executeDelete("cal_calendar_publishablegrouplist", xid);
	}
	return ans;
}
//�����ݱ�Ĳ���
uint64_t CalenderDAO::insert(const cal_calendarDO& iObj)
{
	string sql = "INSERT INTO `cal_calendar` (`xid`, `xcolor`, `xdescription`, `xispublic`, `xname`, `xstatus`, `xtarget`, `xtype`, `xcreateor`, `xcreatetime`, `xupdatetime`, `xsequence`, `xsource`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%s%s%s%s%s%s", iObj.getxId(), iObj.getxColor(), iObj.getxDescription(),
		iObj.getxIsPublic(), iObj.getxName(), iObj.getxStatus(), iObj.getxTarget(), iObj.getxType(), iObj.getxCreateor(), iObj.getxCreateTime(), iObj.getxUpdateTime(), iObj.getxSequence(), iObj.getxSource());
}

// �������������
uint64_t CalenderDAO::insert(const cal_calendar_manageablepersonlistDO& iObj)
{
	return executeInsert("cal_calendar_manageablepersonlist", "xmanageablepersonlist", iObj);
}

// ����ɼ���Χ��������
uint64_t CalenderDAO::insert(const cal_calendar_viewablepersonlistDO& iObj)
{
	return executeInsert("cal_calendar_viewablepersonlist", "xviewablePersonList", iObj);
}

// ����ɼ���Χ����֯����
uint64_t CalenderDAO::insert(const cal_calendar_viewableunitlistDO& iObj)
{
	return executeInsert("cal_calendar_viewableunitlist", "xviewableUnitList", iObj);
}

// ����ɼ���Χ��Ⱥ������
uint64_t CalenderDAO::insert(const cal_calendar_viewablegrouplistDO& iObj)
{
	return executeInsert("cal_calendar_viewablegrouplist", "xviewableGroupList", iObj);
}

// ������½���Χ��������
uint64_t CalenderDAO::insert(const cal_calendar_publishablepersonlistDO& iObj)
{
	return executeInsert("cal_calendar_publishablepersonlist", "xpublishablePersonList", iObj);
}

// ������½���Χ����֯����
uint64_t CalenderDAO::insert(const cal_calendar_publishableunitlistDO& iObj)
{
	return executeInsert("cal_calendar_publishableunitlist", "xpublishableUnitList", iObj);
}

// ������½���Χ��Ⱥ������
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
	//ɾ�������ݱ�����
	if (executeCount("cal_calendar", xid, "xid"))  //�ж��Ƿ����ݴ���
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