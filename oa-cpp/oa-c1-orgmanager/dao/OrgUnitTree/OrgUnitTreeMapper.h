#pragma once
#ifndef _ORGUNITTREE_MAPPER_
#define _ORGUNITTREE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/OrgUnitTree/OrgUnitTreeDO.h"

/**
 * ��֯��λ�ֶ�ƥ��ӳ����
 */
class OrgUnitTreeMapper : public Mapper<OrgUnitTreeDO>
{
public:
    OrgUnitTreeDO mapper(ResultSet* resultSet) const override
    {
        OrgUnitTreeDO data;
        data.setXid(resultSet->getString(1));           // ΨһID
        data.setXname(resultSet->getString(2));         // ��λ����
        data.setXlevelName(resultSet->getString(3));    // �㼶����
        data.setXlevel(resultSet->getInt(4));           // �㼶
        data.setXunique(resultSet->getString(5));       // Ψһ��ʶ
        data.setXsuperior(resultSet->getString(6));     // �ϼ�ID
        return data;
    }
};

#endif // !_ORGUNITTREE_MAPPER_
