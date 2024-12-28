#pragma once
#ifndef PERSONATTRIBUTEDAO
#define PERSONATTRIBUTEDAO

#include "BaseDAO.h"
#include "../../domain/do/org_personattributeDO/org_personattributeDO.h"
class PersonAttributeDAO : public BaseDAO {
public:
    org_PersonAttributeDO selectByUniqueID(const string& id);
    int update(const org_PersonAttributeDO& attributeObj);
    int deleteByUniqueID(const string& uniqueID);
    int insert(const org_PersonAttributeDO& attributeObj);
};
/*
为何一部分传入是string类型 一部分是do类型？
1.
•	selectByUniqueID 方法只需要一个唯一标识符来查找记录，因此使用 string 类型的参数。•	这样设计可以简化查询操作，只需传递一个简单的字符串即可。
2.	更新操作：
•	update 方法需要更新整个对象的所有属性，因此使用 org_PersonAttributeDO 类型的参数。
•	这样设计可以确保所有需要更新的属性都能被传递到方法中，从而保证数据的完整性和一致性。
*/
#endif // !PERSONATTRIBUTEDAO