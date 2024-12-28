#ifndef _PersonAttributeDAO_CPP_
#define _PersonAttributeDAO_CPP_

#include "stdafx.h"
#include "PersonAttributeDAO.h"
#include "PersonAttributeMapper.h"
#include <sstream>



org_PersonAttributeDO PersonAttributeDAO::selectByUniqueID(const string& uniqueID)
{
    PersonalAttributeMapper mapper;
    string sql = "SELECT * FROM org_personattribute WHERE xunique = ?";
    return sqlSession->executeQuery<org_PersonAttributeDO, PersonalAttributeMapper>(sql, mapper, "%s", uniqueID).front();
}

int PersonAttributeDAO::deleteByUniqueID(const string& uniqueID) // sample的id是int  我这里是string
{
    string sql = "DELETE FROM `org_personattribute` WHERE `xunique`=?";
    return sqlSession->executeUpdate(sql, "%s", uniqueID);
}

int PersonAttributeDAO::update(const org_PersonAttributeDO& attributeObj)
{
    // 构建更新语句，只更新description字段
    std::string sql = "UPDATE org_personattribute SET `xdescription` = ? WHERE `xunique` = ?";

    // 执行更新操作
    return sqlSession->executeUpdate(sql,
        "%s%s", // 参数格式化字符串
        attributeObj.getXdescription(),
        attributeObj.getXunique());
}

int PersonAttributeDAO::insert(const org_PersonAttributeDO& attributeObj)
{
    // 构建插入语句
    std::string sql = "INSERT INTO `org_personattribute` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xdescription`, `xdistinguishedName`, `xname`, `xorderNumber`, `xperson`, `xpinyin`, `xpinyinInitial`, `xunique`) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    // 执行插入操作
    return sqlSession->executeUpdate(sql,
        "%s%s%s%s%i%s%s%s%i%s%s%s%s",
        attributeObj.getXid(),
        attributeObj.getXcreateTime(),
        attributeObj.getXsequence(),
        attributeObj.getXupdateTime(),
        attributeObj.getXDistributeFactor(),
        attributeObj.getXdescription(),
        attributeObj.getXDistinguishedName(),
        attributeObj.getXname(),
        attributeObj.getXorderNumber(),
        attributeObj.getXperson(),
        attributeObj.getXpinyin(),
        attributeObj.getXpinyinInitial(),
        attributeObj.getXunique());
}

#endif // !_PersonAttributeDAO_CPP_