#pragma once
#pragma once
#ifndef PERSONALATTRIBUTE_MAPPER_H
#define PERSONALATTRIBUTE_MAPPER_H

#include "Mapper.h"
#include "../../domain/do/org_personattributeDO/org_personattributeDO.h"

class PersonalAttributeMapper : public Mapper<org_PersonAttributeDO> {
public:
    org_PersonAttributeDO mapper(ResultSet* res) const override {
        org_PersonAttributeDO data;
        data.setXid(res->getString("xid"));
        data.setXsequence(res->getString("xsequence")); // 聪res对象中获取xsequence的值 并将其设置到data对象的xsequence属性中
        data.setXupdateTime(res->getString("xupdateTime"));
        data.setXcreateTime(res->getString("xcreateTime"));
        data.setXDistributeFactor(res->getInt("xdistributeFactor"));
        data.setXdescription(res->getString("xdescription"));
        data.setXDistinguishedName(res->getString("xdistinguishedName"));
        data.setXname(res->getString("xname"));
        data.setXorderNumber(res->getInt("xorderNumber"));
        data.setXperson(res->getString("xperson"));
        data.setXpinyin(res->getString("xpinyin"));
        data.setXpinyinInitial(res->getString("xpinyinInitial"));
        data.setXunique(res->getString("xunique"));
        return data;
    }
};

#endif // PERSONALATTRIBUTE_MAPPER_H