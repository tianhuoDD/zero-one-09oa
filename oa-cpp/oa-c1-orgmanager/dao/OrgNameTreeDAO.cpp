#include "stdafx.h"
#include "OrgNameTreeDAO.h"
#include "OrgNameMapper.h"

std::list<OrgNameTreeDO> OrgNameTreeDAO::selectAllOrgNameTree()
{
	string sql = "SELECT xid,xname, xunique,xlevel, xlevelname, xsuperior, xlevelOrderNumber FROM org_unit";
	OrgNameMapper mapper;
	return sqlSession->executeQuery<OrgNameTreeDO, OrgNameMapper>(sql, mapper);
}