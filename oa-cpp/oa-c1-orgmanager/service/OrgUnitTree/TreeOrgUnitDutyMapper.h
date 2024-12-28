#pragma once
#ifndef _TREEORGUNITDUTYMAPPER_H_
#define _TREEORGUNITDUTYMAPPER_H_

#include "tree/TreeNodeMapper.h"
#include "domain/do/OrgUnitTree/OrgUnitTreeDO.h"
#include "domain/dto/OrgUnitTree/OrgUnitDutyTreeDTO.h"
#include "../../domain/do/OrgUnitTree/OrgUnitDutyTreeDO.h"

class TreeOrgUnitDutyMapper : public TreeNodeMapper<OrgUnitTreeDO> {
public:
    map<string, list<OrgUnitDutyTreeDO>> dutyMap;

    TreeOrgUnitDutyMapper(const map<string, list<OrgUnitDutyTreeDO>>& dutyMap) : dutyMap(dutyMap) {}

    shared_ptr<TreeNode> objectMapper(OrgUnitTreeDO* source) const override {
        auto res = make_shared<OrgUnitDutyTreeDTO>();
        res->_id(source->getXid());
        res->_pid(source->getXsuperior());

        res->name = source->getXname();
        res->levelName = source->getXlevelName();
        res->level = source->getXlevel();
        res->unique = source->getXunique();

        // 关联职务信息
        auto it = dutyMap.find(source->getXid());
        if (it != dutyMap.end()) {
            auto duties = List<Object<OrgUnitDutyTree>>::createShared();
            for (const auto& duty : it->second) {
                auto dutyItem = OrgUnitDutyTree::createShared();
                dutyItem->xname = duty.getXname();
                dutyItem->xunique = duty.getXunique();
                duties->push_back(dutyItem);
            }
            res->duties = duties;
        }

        return res;
    }
};

#endif // !_TREEORGUNITDUTYMAPPER_H_
