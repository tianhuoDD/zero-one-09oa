#pragma once
#ifndef _ORGUNITIDENTITYTREEDTO_H_
#define _ORGUNITIDENTITYTREEDTO_H_

#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 定义成员信息的数据结构
class IdentityMember : public oatpp::DTO
{
    DTO_INIT(IdentityMember, DTO);

    API_DTO_FIELD_DEFAULT(String, mam_name, ZH_WORDS_GETTER("identity_member.field.mam_name"));   // 成员名称
    API_DTO_FIELD_DEFAULT(String, mam_unique, ZH_WORDS_GETTER("identity_member.field.mam_unique")); // 成员唯一标识
};

/**
 * 组织单位数据传输对象
 */
class OrgUnitIdentityTreeDTO : public oatpp::DTO, public TreeNode
{
    DTO_INIT(OrgUnitIdentityTreeDTO, DTO);

    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("org_unit.field.name"));              // 单位名称
    API_DTO_FIELD_DEFAULT(String, levelName, ZH_WORDS_GETTER("org_unit.field.levelname"));    // 层级名称
    API_DTO_FIELD(Int32, level, ZH_WORDS_GETTER("org_unit.field.level"), false, 0);           // 层级
    //API_DTO_FIELD_DEFAULT(Int32, level, ZH_WORDS_GETTER("org_unit.field.level"));             // 层级
    API_DTO_FIELD_DEFAULT(String, unique, ZH_WORDS_GETTER("org_unit.field.unique"));          // 唯一标识

    // 新增字段: 组织成员信息
    API_DTO_FIELD(List<Object<IdentityMember>>, members, ZH_WORDS_GETTER("org_unit.field.members"), false, {});

    API_DTO_FIELD(List<OrgUnitIdentityTreeDTO::Wrapper>, subordinates, ZH_WORDS_GETTER("org_unit.field.subordinates"), false, {});

public:
    void addChild(shared_ptr<TreeNode> child) override
    {
        subordinates->push_back(Wrapper(dynamic_pointer_cast<OrgUnitIdentityTreeDTO>(child), Wrapper::Class::getType()));
    }
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGUNITIDENTITYTREEDTO_H_
