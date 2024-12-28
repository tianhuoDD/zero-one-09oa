#include "stdafx.h"
#include "Attrib_add_DAO.h"
#include "Attrib_add_Mapper.h"
#include <sstream>
#include "oatpp/core/utils/String.hpp"
#include "../../lib-common/include/SnowFlake.h"

//定义条件解析宏，减少重复代码  
#define ATTRIB_TERAM_PARSE(iObj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (iObj.getXid().size()) { \
	sql << " AND xunique=? "; \
	SQLPARAMS_PUSH(params, "s", string, iObj.getXid()); \
}\

//对数据库进行操作

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!同一组织下的属性值要唯一

uint64_t Attrib_add_DAO::select(const Attrib_add_DO& iObj)
{//,org_unitattribute,org_unitattribute_attributelist
	stringstream sql;
	sql << "SELECT xunique FROM org_unit";
	ATTRIB_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

////去对应的组织里存的属性表插入数据
//uint64_t Attrib_add_DAO::insert1(const Attrib_add_DO& iObj)//第三张表(org_unitattribute_attributelist) id,属性
//{	
//	//关联字段--与org_unit的xunique关联(UNITATTRIBUTE_XID)，属性列表--属性(xattributeList)
//	string sql = "INSERT INTO `org_unitattribute_attributelist` (`UNITATTRIBUTE_XID`, `xattributeList`) VALUES (?, ?); ";
//	return sqlSession->executeInsert(sql, "%s%s", to_string(iObj.getId()), iObj.getShuxing());
//}

uint64_t Attrib_add_DAO::insert2(const Attrib_add_DO& iObj)//第二张表(org_unitattribute)  id,名称,值，描述
{	
	//主键(xid)，创建时间(xcreateTime)，更新时间(xupdateTime)，分发因子--值(xdistributeFactor)，描述信息(xdescription)，
	//属性值(xdistinguishedName),组织名称(xname)，唯一标识--唯一编码(xunique)
	SnowFlake sf(1, 1);
	string sql = "INSERT INTO `org_unitattribute` (`xid`,`xdistributeFactor`,`xdescription`,`xdistinguishedName`,`xname`,`xunique`) VALUES (?, ?, ?, ?, ?, ?); ";
	return sqlSession->executeInsert(sql, "%s%i%s%s%s%s", to_string(sf.nextId()), iObj.getXdistributeFactor(), iObj.getXdescription(), iObj.getXdistinguishedName(), iObj.getXname(), iObj.getXid());
}
