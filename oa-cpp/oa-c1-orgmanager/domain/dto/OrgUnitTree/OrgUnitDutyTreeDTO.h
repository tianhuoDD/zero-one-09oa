#pragma once
#ifndef _ORGUNITDUTYTREEDTO_H_
#define _ORGUNITDUTYTREEDTO_H_

#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OrgUnitDutyTree : public oatpp::DTO {
    DTO_INIT(OrgUnitDutyTree, DTO);

    API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("org_unitduty.field.xname")); // ְ������
    API_DTO_FIELD_DEFAULT(String, xunique, ZH_WORDS_GETTER("org_unitduty.field.xunique")); // ְ��Ψһ��ʶ
};

class OrgUnitDutyTreeDTO : public oatpp::DTO, public TreeNode {
    DTO_INIT(OrgUnitDutyTreeDTO, DTO);

    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("org_unit.field.name"));         // ��λ����
    API_DTO_FIELD_DEFAULT(String, levelName, ZH_WORDS_GETTER("org_unit.field.levelname")); // �㼶����
    API_DTO_FIELD(Int32, level, ZH_WORDS_GETTER("org_unit.field.level"), false, 0);      // �㼶
    API_DTO_FIELD_DEFAULT(String, unique, ZH_WORDS_GETTER("org_unit.field.unique"));     // Ψһ��ʶ

    // �����ֶ�: ���ְ����Ϣ
    API_DTO_FIELD(List<Object<OrgUnitDutyTree>>, duties, ZH_WORDS_GETTER("org_unitduty.field.duties"), false, {});

    API_DTO_FIELD(List<OrgUnitDutyTreeDTO::Wrapper>, subordinates, ZH_WORDS_GETTER("org_unit.field.subordinates"), false, {});

public:
    void addChild(shared_ptr<TreeNode> child) override {
        subordinates->push_back(Wrapper(dynamic_pointer_cast<OrgUnitDutyTreeDTO>(child), Wrapper::Class::getType()));
    }
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGUNITDUTYTREEDTO_H_
