#include "OrgUnitTreeController.h"
#include "dao/OrgUnitTree/OrgUnitTreeDAO.h"
#include "service/OrgUnitTree/TreeOrgUnitIdentityMapper.h"
#include "service/OrgUnitTree/TreeOrgUnitDutyMapper.h"
#include "tree/TreeUtil.h"

OrgUnitIdentityTreeJsonVO::Wrapper OrgUnitTreeController::executeQueryOrgUnitIdentityTree(const PayloadDTO& payload) {
    auto vo = OrgUnitIdentityTreeJsonVO::createShared();
    OrgUnitTreeDAO orgUnitDao;

    auto unitList = orgUnitDao.selectAllOrgUnitTree();
    auto identityMap = orgUnitDao.selectAllOrgUnitIdentities();

    list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<OrgUnitTreeDO>(unitList, TreeOrgUnitIdentityMapper(identityMap));

    for (shared_ptr<TreeNode> one : res) {
        vo->data->push_back(OrgUnitIdentityTreeDTO::Wrapper(dynamic_pointer_cast<OrgUnitIdentityTreeDTO>(one), OrgUnitIdentityTreeDTO::Wrapper::Class::getType()));
    }

    return vo;
}

OrgUnitDutyTreeJsonVO::Wrapper OrgUnitTreeController::executeQueryOrgUnitDutyTree(const PayloadDTO& payload) {
    auto vo = OrgUnitDutyTreeJsonVO::createShared();
    OrgUnitTreeDAO orgUnitDao;

    auto unitList = orgUnitDao.selectAllOrgUnitTree();
    auto dutyMap = orgUnitDao.selectAllOrgUnitDuties();

    list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<OrgUnitTreeDO>(unitList, TreeOrgUnitDutyMapper(dutyMap));

    for (shared_ptr<TreeNode> one : res) {
        vo->data->push_back(OrgUnitDutyTreeDTO::Wrapper(dynamic_pointer_cast<OrgUnitDutyTreeDTO>(one), OrgUnitDutyTreeDTO::Wrapper::Class::getType()));
    }

    return vo;
}
