#include "OrgUnitTreeDAO.h"
#include "OrgUnitTreeMapper.h"
#include "OrgUnitIdentityTreeMapper.h"
#include "OrgUnitDutyTreeMapper.h"

std::list<OrgUnitTreeDO> OrgUnitTreeDAO::selectAllOrgUnitTree() {
    string sql = "SELECT xid, xname, xlevelname, xlevel, xunique, xsuperior FROM org_unit";
    OrgUnitTreeMapper mapper;
    return sqlSession->executeQuery<OrgUnitTreeDO, OrgUnitTreeMapper>(sql, mapper);
}

map<string, list<OrgUnitIdentityTreeDO>> OrgUnitTreeDAO::selectAllOrgUnitIdentities() {
    string sql = "SELECT xid, xname, xunique, xunit FROM org_identity";
    OrgUnitIdentityTreeMapper mapper;
    auto identityList = sqlSession->executeQuery<OrgUnitIdentityTreeDO, OrgUnitIdentityTreeMapper>(sql, mapper);

    map<string, list<OrgUnitIdentityTreeDO>> identityMap;
    for (const auto& identity : identityList) {
        identityMap[identity.getXunit()].push_back(identity);
    }
    return identityMap;
}

map<string, list<OrgUnitDutyTreeDO>> OrgUnitTreeDAO::selectAllOrgUnitDuties() {
    string sql = "SELECT xid, xname, xunique, xunit FROM org_unitduty";
    OrgUnitDutyTreeMapper mapper;
    auto dutiesList = sqlSession->executeQuery<OrgUnitDutyTreeDO, OrgUnitDutyTreeMapper>(sql, mapper);

    map<string, list<OrgUnitDutyTreeDO>> dutyMap;
    for (const auto& duty : dutiesList) {
        dutyMap[duty.getXunit()].push_back(duty);
    }
    return dutyMap;
}
