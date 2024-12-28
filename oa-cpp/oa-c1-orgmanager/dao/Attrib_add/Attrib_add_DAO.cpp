#include "stdafx.h"
#include "Attrib_add_DAO.h"
#include "Attrib_add_Mapper.h"
#include <sstream>
#include "oatpp/core/utils/String.hpp"
#include "../../lib-common/include/SnowFlake.h"

//�������������꣬�����ظ�����  
#define ATTRIB_TERAM_PARSE(iObj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (iObj.getXid().size()) { \
	sql << " AND xunique=? "; \
	SQLPARAMS_PUSH(params, "s", string, iObj.getXid()); \
}\

//�����ݿ���в���

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ͬһ��֯�µ�����ֵҪΨһ

uint64_t Attrib_add_DAO::select(const Attrib_add_DO& iObj)
{//,org_unitattribute,org_unitattribute_attributelist
	stringstream sql;
	sql << "SELECT xunique FROM org_unit";
	ATTRIB_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

////ȥ��Ӧ����֯�������Ա��������
//uint64_t Attrib_add_DAO::insert1(const Attrib_add_DO& iObj)//�����ű�(org_unitattribute_attributelist) id,����
//{	
//	//�����ֶ�--��org_unit��xunique����(UNITATTRIBUTE_XID)�������б�--����(xattributeList)
//	string sql = "INSERT INTO `org_unitattribute_attributelist` (`UNITATTRIBUTE_XID`, `xattributeList`) VALUES (?, ?); ";
//	return sqlSession->executeInsert(sql, "%s%s", to_string(iObj.getId()), iObj.getShuxing());
//}

uint64_t Attrib_add_DAO::insert2(const Attrib_add_DO& iObj)//�ڶ��ű�(org_unitattribute)  id,����,ֵ������
{	
	//����(xid)������ʱ��(xcreateTime)������ʱ��(xupdateTime)���ַ�����--ֵ(xdistributeFactor)��������Ϣ(xdescription)��
	//����ֵ(xdistinguishedName),��֯����(xname)��Ψһ��ʶ--Ψһ����(xunique)
	SnowFlake sf(1, 1);
	string sql = "INSERT INTO `org_unitattribute` (`xid`,`xdistributeFactor`,`xdescription`,`xdistinguishedName`,`xname`,`xunique`) VALUES (?, ?, ?, ?, ?, ?); ";
	return sqlSession->executeInsert(sql, "%s%i%s%s%s%s", to_string(sf.nextId()), iObj.getXdistributeFactor(), iObj.getXdescription(), iObj.getXdistinguishedName(), iObj.getXname(), iObj.getXid());
}
