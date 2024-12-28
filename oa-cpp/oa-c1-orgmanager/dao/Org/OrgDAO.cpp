#include "OrgDAO.h"
#include "dao/Org/StringMapper.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

//创建一个通用的返回string类型的mapper
StringMapper smapper;

int OrgDAO::insert(CreateOrgDO& coDO)
{
	//插入前先检查是否存在相同的xunique
	int ret = sqlSession->executeQueryNumerical("SELECT COUNT(*) FROM org_unit WHERE xunique=?", "%s", coDO.getXunique());
	if (ret > 0)return -2;

	// 插入 org_unit 表中的字段===============================================================================
	string xdistinguishedName = coDO.getXname() + "@" + coDO.getXunique() + "@U";

	//拼xlevelName
	string xlevelName = "";
	if (coDO.getXsuperior().empty())
	{
		//如果没传上级组织，那么这次插入的就是一级组织，改成1以防万一
		coDO.setXlevel(1);
		//一级组织的xlevelName就是xname
		xlevelName = coDO.getXname();
	}
	else
	{
		//如果传进来了上级组织的xid
		//上级组织的xlevel
		int slevel = sqlSession->executeQueryNumerical("SELECT xlevel FROM org_unit WHERE xid=?", "%s", coDO.getXsuperior());
		//更新新建组织的xlevel（以防万一）
		coDO.setXlevel(slevel + 1);
		//根据上级组织xid找上级组织的xlevelName
		//string sxlevelName = sqlSession->executeQueryString("SELECT xlevelName FROM org_unit WHERE xid=?", "%s", coDO.getXsuperior());
		string sxlevelName = sqlSession->executeQuery<string, StringMapper>("SELECT xlevelName FROM org_unit WHERE xid=?", smapper, "%s", coDO.getXsuperior()).front();
		//拼新建组织的xlevelName
		xlevelName = sxlevelName + "/" + coDO.getXname();
		/*
		//如果有上级组织，想要通过传入的上级组织名字查找就需要注意重复问题：
		//如果传入的上级组织名字在不同的两层都有，该如何选择
		//这里选择相信传入的xlevel，根据xlevel确定
		if (coDO.getXlevel() >= 2)
		{
			//上级组织的level
			int slevel = coDO.getXlevel() - 1;
			//上级组织的名字
			string sname = coDO.getXsuperior();
			//通过上级组织名字和level查找上级组织的xlevelName
			string sql = "SELECT xlevelName FROM org_unit WHERE xname=? AND xlevel=?";
			auto superiorLevelName = sqlSession->executeQueryString(sql, "%s%i", sname, slevel);
			if (superiorLevelName.empty())
			{
				cout << "OrgUnitDAO::insert: can not find superiorLevelName" << endl;
				return -3;
			}
			xlevelName = superiorLevelName + "/" + coDO.getXname();
			//趁着找上级，顺便也将xsuperior中的上级组织名称改成需要的上级组织xid
			coDO.setXsuperior(sqlSession->executeQueryString("SELECT xid FROM org_unit WHERE xname=? AND xlevel=?", "%s%i", sname, slevel));
		}
		else
		{
			cout << "OrgUnitDAO::insert: xlevel is error" << endl;
			return -3;
		}
		*/
	}

	//检查是否存在同一层有相同的xname
	ret = sqlSession->executeQueryNumerical("SELECT COUNT(*) FROM org_unit WHERE xlevel=? AND xname=?", "%i%s", coDO.getXlevel(), coDO.getXname());
	if (ret > 0)return -4;
	//debug
	cout << "OrgUnitDAO::insert: xdistinguishedName=" << xdistinguishedName << endl;
	cout << "OrgUnitDAO::insert: xlevelName=" << xlevelName << endl;
	cout << "OrgUnitDAO::insert: xsuperior=" << coDO.getXsuperior() << endl;

	//先把一些基础的能插入的字段数据插入到org_unit表中
	string params = "(`xid`,`xcreateTime`,`xupdateTime`,`xdescription`,`xdistinguishedName`,`xlevel`,`xlevelName`,`xname`,`xshortName`,`xsuperior`,`xunique`,`xpinyin`,`xpinyinInitial`)";
	string values = "(UUID(),NOW(),NOW(),?,?,?,?,?,?,?,?,?,?)";
	string sql = "INSERT INTO `org_unit`" + params + " VALUES " + values;

	ret = sqlSession->executeUpdate(sql, "%s%s%i%s%s%s%s%s%s%s",
		coDO.getXdescription(), xdistinguishedName, coDO.getXlevel(), xlevelName, coDO.getXname(), coDO.getXshortName(),
		coDO.getXsuperior(), coDO.getXunique(),coDO.getXpinyin(), coDO.getXpinyinInitial());
	if (ret != 1)return ret;

	//更新刚插入的数据，补充xsequence
	//string time = sqlSession->executeQueryString("SELECT DATE_FORMAT(xcreateTime, '%Y%m%d%H%i%s') AS formatted_createtime FROM org_unit WHERE xunique=?", "%s", coDO.getXunique());
	string time = sqlSession->executeQuery<string, StringMapper>("SELECT DATE_FORMAT(xcreateTime, '%Y%m%d%H%i%s') AS formatted_createtime FROM org_unit WHERE xunique=?", smapper, "%s", coDO.getXunique()).front();
	//string xid = sqlSession->executeQueryString("SELECT xid FROM org_unit WHERE xunique=?", "%s", coDO.getXunique());
	string xid = sqlSession->executeQuery<string, StringMapper>("SELECT xid FROM org_unit WHERE xunique=?", smapper, "%s", coDO.getXunique()).front();
	string xsequence = time + xid;
	sqlSession->executeUpdate("UPDATE `org_unit` SET `xsequence`=? WHERE `xid`=?", "%s%s", xsequence, xid);

	//补充xorderNumber
	int xorderNumber;//后面还要用到
	if (coDO.getXorderNumber() != -999999)
	{
		//如果传进来了
		xorderNumber = coDO.getXorderNumber();
		sqlSession->executeUpdate("UPDATE `org_unit` SET `xorderNumber`=? WHERE `xid`=?", "%i%s", coDO.getXorderNumber(), xid);
	}
	else
	{
		//如果没有传进来
		//先生成一个秒数的xorderNumber
		xorderNumber = sqlSession->executeQueryNumerical("SELECT UNIX_TIMESTAMP(NOW()) - UNIX_TIMESTAMP('2024-01-01 00:00:00')");
		sqlSession->executeUpdate("UPDATE `org_unit` SET `xorderNumber`=? WHERE `xid`=?", "%i%s", xorderNumber, xid);
	}

	//拼xlevelOrderNumber插入
	//先将xorderNumber转成符合格式的字符串
	stringstream ss;
	ss << setw(10) << setfill('0') << xorderNumber;
	//如果就是一级组织
	if (coDO.getXlevel() == 1)
	{
		//xlevelOrderNumber就是xorderNumber
		string xlevelOrderNumber = ss.str();
		sqlSession->executeUpdate("UPDATE `org_unit` SET `xlevelOrderNumber`=? WHERE `xid`=?", "%s%s", xlevelOrderNumber, xid);
	}
	else
	{
		//如果不是一级组织
		//先找到上级组织的xlevelOrderNumber
		//string xlevelOrderNumber = sqlSession->executeQueryString("SELECT xlevelOrderNumber FROM org_unit WHERE xid=?", "%s", coDO.getXsuperior());
		string xlevelOrderNumber = sqlSession->executeQuery<string, StringMapper>("SELECT xlevelOrderNumber FROM org_unit WHERE xid=?", smapper, "%s", coDO.getXsuperior()).front();
		//拼接上级组织的xlevelOrderNumber和本组织的xorderNumber
		xlevelOrderNumber += ("/" + ss.str());
		sqlSession->executeUpdate("UPDATE `org_unit` SET `xlevelOrderNumber`=? WHERE `xid`=?", "%s%s", xlevelOrderNumber, xid);
	}

	//插入拼音
	//Pinyin pytool;
	//string xpinyin;//全拼
	//string xname = coDO.getXname();
	//pytool.GetPinYin(xname, xpinyin);
	//string xpinyinInitial;//首字母拼音
	/*string temp;
	for (int i = 0; i < xname.length(); i++)
	{
		temp="";
		pytool.GetPinYin(to_string(xname[i]), temp);
		cout<<"temp="<<temp<<endl;
		xpinyinInitial += temp[0];
	}*/

	//debug
	//cout << "OrgUnitDAO::insert: xpinyin=" << xpinyin << endl;
	//cout << "OrgUnitDAO::insert: xpinyinInitial=" << xpinyinInitial << endl;
	//sqlSession->executeUpdate("UPDATE `org_unit` SET `xpinyin`=? WHERE `xid`=?", "%s%s", xpinyin, xid);

	// 插入 org_unit_controllerlist 表中的字段===============================================================================
	int cnt = sqlSession->executeQueryNumerical("SELECT COUNT(*) FROM org_unit_controllerlist WHERE UNIT_XID=?", "%s", xid);
	for (auto& controller : coDO.getXcontrollerList())
	{
		sqlSession->executeUpdate("INSERT INTO `org_unit_controllerlist`(`UNIT_XID`,`xcontrollerList`,`xorderColumn`) VALUES (?,?,?)", "%s%s%i", xid, controller, cnt);
		cnt++;
	}

	// 插入 org_unit_typelist 表中的字段===============================================================================
	//cnt = sqlSession->executeQueryNumerical("SELECT COUNT(*) FROM org_unit_typelist WHERE UNIT_XID=?", "%s", xid);
	//for (auto& type : coDO.getXtypeList())
	//{
	//	sqlSession->executeUpdate("INSERT INTO `org_unit_typelist`(`UNIT_XID`,`xtypeList`,`xorderColumn`) VALUES (?,?,?)", "%s%s%i", xid, type, cnt);
	//	cnt++;
	//}
	sqlSession->executeUpdate("INSERT INTO `org_unit_typelist`(`UNIT_XID`,`xtypeList`,`xorderColumn`) VALUES (?,?,?)", "%s%s%i", xid, coDO.getXtypeList(), 0);

	return 1;

}

void OrgDAO::batchDelete(DeleteOrgDO& doDO, int& cnt)
{
	//要删除的组织xid
	string xid = doDO.getXid();
	//找上级组织是这个xid的组织xid
	auto subOrgXidList = sqlSession->executeQuery<string, StringMapper>("SELECT xid FROM org_unit WHERE xsuperior=?", smapper, "%s", xid);

	//准备删除org_unit表的sql语句
	string sql_unit = "DELETE FROM `org_unit` WHERE `xid`=?";
	//准备删除org_unit_controllerlist表的sql语句
	string sql_controllerlist = "DELETE FROM `org_unit_controllerlist` WHERE `UNIT_XID`=?";
	//准备删除org_unit_typelist表的sql语句
	string sql_typelist = "DELETE FROM `org_unit_typelist` WHERE `UNIT_XID`=?";

	//先删除自己
	int ret = sqlSession->executeUpdate(sql_unit, "%s", xid);
	if (ret == 1)cnt++;
	sqlSession->executeUpdate(sql_controllerlist, "%s", xid);
	sqlSession->executeUpdate(sql_typelist, "%s", xid);

	//再删除子组织
	for (auto& subOrgXid : subOrgXidList)
	{
		DeleteOrgDO subDO;
		subDO.setXid(subOrgXid);
		batchDelete(subDO, cnt);
	}

	/*
	//准备删除org_unit表的sql语句
	string sql_unit = "DELETE FROM `org_unit` WHERE `xunique`=?";
	string sql_controllerlist = "DELETE FROM `org_unit_controllerlist` WHERE `UNIT_XID`=?";
	string sql_typelist = "DELETE FROM `org_unit_typelist` WHERE `UNIT_XID`=?";
	//准备返回值（统计删除的xunique数量）
	int cnt = 0;

	//循环删除
	for (auto& xunique : doDO.getXuniqueList())
	{
		//先把要删除的xid找出来
		//string xid = sqlSession->executeQueryString("SELECT xid FROM org_unit WHERE xunique=?", "%s", xunique);
		string xid = sqlSession->executeQuery<string, StringMapper>("SELECT xid FROM org_unit WHERE xunique=?", smapper, "%s", xunique).front();
		//如果字符串为空，说明没找到
		if (xid.empty())continue;

		int ret = sqlSession->executeUpdate(sql_unit, "%s", xunique);
		if (ret == 1)cnt++;
		sqlSession->executeUpdate(sql_controllerlist, "%s", xid);
		sqlSession->executeUpdate(sql_typelist, "%s", xid);

	}
	*/
	//return cnt;
}
