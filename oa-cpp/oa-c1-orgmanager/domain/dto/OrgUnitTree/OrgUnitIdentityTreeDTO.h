#pragma once
#ifndef _ORGUNITIDENTITYTREEDTO_H_
#define _ORGUNITIDENTITYTREEDTO_H_

#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// �����Ա��Ϣ�����ݽṹ
class IdentityMember : public oatpp::DTO
{
    DTO_INIT(IdentityMember, DTO);

    API_DTO_FIELD_DEFAULT(String, mam_name, ZH_WORDS_GETTER("identity_member.field.mam_name"));   // ��Ա����
    API_DTO_FIELD_DEFAULT(String, mam_unique, ZH_WORDS_GETTER("identity_member.field.mam_unique")); // ��ԱΨһ��ʶ
};

/**
 * ��֯��λ���ݴ������
 */
class OrgUnitIdentityTreeDTO : public oatpp::DTO, public TreeNode
{
    DTO_INIT(OrgUnitIdentityTreeDTO, DTO);

    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("org_unit.field.name"));              // ��λ����
    API_DTO_FIELD_DEFAULT(String, levelName, ZH_WORDS_GETTER("org_unit.field.levelname"));    // �㼶����
    API_DTO_FIELD(Int32, level, ZH_WORDS_GETTER("org_unit.field.level"), false, 0);           // �㼶
    //API_DTO_FIELD_DEFAULT(Int32, level, ZH_WORDS_GETTER("org_unit.field.level"));             // �㼶
    API_DTO_FIELD_DEFAULT(String, unique, ZH_WORDS_GETTER("org_unit.field.unique"));          // Ψһ��ʶ

    // �����ֶ�: ��֯��Ա��Ϣ
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
