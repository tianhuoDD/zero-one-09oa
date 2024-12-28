#pragma once
#ifndef _ORGUNITTREE_MAPPER_
#define _ORGUNITTREE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/OrgUnitTree/OrgUnitTreeDO.h"

/**
 * 组织单位字段匹配映射器
 */
class OrgUnitTreeMapper : public Mapper<OrgUnitTreeDO>
{
public:
    OrgUnitTreeDO mapper(ResultSet* resultSet) const override
    {
        OrgUnitTreeDO data;
        data.setXid(resultSet->getString(1));           // 唯一ID
        data.setXname(resultSet->getString(2));         // 单位名称
        data.setXlevelName(resultSet->getString(3));    // 层级名称
        data.setXlevel(resultSet->getInt(4));           // 层级
        data.setXunique(resultSet->getString(5));       // 唯一标识
        data.setXsuperior(resultSet->getString(6));     // 上级ID
        return data;
    }
};

#endif // !_ORGUNITTREE_MAPPER_
