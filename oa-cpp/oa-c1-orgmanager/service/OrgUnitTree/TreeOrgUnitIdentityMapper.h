#pragma once
#ifndef _TREEORGUNITIDENTITYMAPPER_H_
#define _TREEORGUNITIDENTITYMAPPER_H_

#include "tree/TreeNodeMapper.h"
#include "domain/do/OrgUnitTree/OrgUnitTreeDO.h"
#include "domain/dto/OrgUnitTree/OrgUnitIdentityTreeDTO.h"
#include "../../domain/do/OrgUnitTree/OrgUnitIdentityTreeDO.h"

class TreeOrgUnitIdentityMapper : public TreeNodeMapper<OrgUnitTreeDO>
{
public:
    map<string, list<OrgUnitIdentityTreeDO>> identityMap;

    TreeOrgUnitIdentityMapper(const map<string, list<OrgUnitIdentityTreeDO>>& identityMap) : identityMap(identityMap) {}

    shared_ptr<TreeNode> objectMapper(OrgUnitTreeDO* source) const override
    {
        auto res = make_shared<OrgUnitIdentityTreeDTO>();
        res->_id(source->getXid());
        res->_pid(source->getXsuperior());

        res->name = source->getXname();
        res->levelName = source->getXlevelName();
        res->level = source->getXlevel();
        res->unique = source->getXunique();

        // 关联成员信息
        auto it = identityMap.find(source->getXid());
        if (it != identityMap.end())
        {
            auto members = List<Object<IdentityMember>>::createShared();
            for (const auto& identity : it->second)
            {
                auto member = IdentityMember::createShared();
                member->mam_name = identity.getXname();
                member->mam_unique = identity.getXunique();
                members->push_back(member);
            }
            res->members = members;
        }

        return res;
    }
};

#endif // !_TREEORGUNITIDENTITYMAPPER_H_
