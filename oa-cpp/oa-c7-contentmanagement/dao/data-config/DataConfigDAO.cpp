/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include <sstream>
#include "DataConfigDAO.h"
#include "DataConfigMapper.h"

string DataConfigDAO::insertDict(const DictDO& iObj)
{
	string sql = "INSERT INTO `cms_appndict` (`xid`, `xcreateTime`, `xsequence`,`xupdateTime`, `xalias`, `xappId`, `xdescription`, `xname`) VALUES (?, ?, ? ,?, ?, ?, ?, ?)";
	sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", iObj.getXid(), iObj.getXcreateTime(), iObj.getXsequence(), iObj.getXupdateTime(), iObj.getXalias(), iObj.getXappId(), iObj.getXdescription(), iObj.getXname());
	return iObj.getXid();
}

string DataConfigDAO::insertItem(vector<ItemDO>& v) {
	string sql = "INSERT INTO `cms_appdictitem` (`xid`, `xcreateTime`, `xsequence`,`xupdateTime`, `xappId`, `xbooleanvalue`,`xbundle`, `xitemCategory`,`xitemPrimitiveType`, `xitemStringValueType`,\
    `xitemType`, `xnumberValue`,`xpath0`, `xpath0Location`,`xpath1`, `xpath1Location`,`xpath2`, `xpath2Location`,`xpath3`, `xpath3Location`,\
    `xpath4`, `xpath4Location`,`xpath5`, `xpath5Location`,`xpath6`, `xpath6Location`,`xpath7`, `xpath7Location`,`xstringShortValue`)\
	 VALUES (?, ?, ? ,?, ?, ?, ?, ?, ?, ? , ?, ?, ? ,?, ?, ?, ?, ?, ?, ?, ?, ?, ? ,?, ?, ?, ?, ?, ?)";
	//±éÀúÈÝÆ÷Ö´ÐÐÌí¼Ó
	for (int i = 0; i < v.size(); i++)
	{
		sqlSession->executeUpdate(sql, "%s%s%s%s%s%i%s%s%s%s%s%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", \
		v[i].getXid(), v[i].getXcreateTime(), v[i].getXsequence(), v[i].getXupdateTime(), v[i].getXappId(), v[i].getXbooleanValue(), v[i].getXbundle(), v[i].getXitemCategory(), v[i].getXitemPrimitiveType(),\
		v[i].getXitemStringValueType(), v[i].getXitemType(), v[i].getXnumberValue(), v[i].getXpath0(), v[i].getXpath0Location(), v[i].getXpath1(), v[i].getXpath1Location(), v[i].getXpath2(), v[i].getXpath2Location(), v[i].getXpath3(), v[i].getXpath3Location(), \
		v[i].getXpath4(), v[i].getXpath4Location(), v[i].getXpath5(), v[i].getXpath5Location(), v[i].getXpath6(), v[i].getXpath6Location(), v[i].getXpath7(), v[i].getXpath7Location(), v[i].getXstringShortValue());
	}
	return "";
}

int DataConfigDAO::deleteById(string xid) {
	string sql = "DELETE FROM `cms_appndict` WHERE `xid`=?";
	sqlSession->executeUpdate(sql, "%s", xid);
	sql = "DELETE FROM `cms_appdictitem` WHERE `xbundle`=?";
	sqlSession->executeUpdate(sql, "%s", xid);

	return 0;
}

list<DictDO> DataConfigDAO::selectDictByXid(const string& xid) {
	string sql = "SELECT * FROM cms_appndict WHERE `xid` = ?";
	DictMapper mapper; 
	return sqlSession->executeQuery<DictDO, DictMapper>(sql, mapper, "%s", xid);
}

list<ItemDO> DataConfigDAO::selectItemByXid(const string& xid) {
	string sql = "SELECT * FROM cms_appdictitem WHERE `xbundle` = ?";
	ItemMapper mapper;
	return sqlSession->executeQuery<ItemDO, ItemMapper>(sql, mapper, "%s", xid);
}