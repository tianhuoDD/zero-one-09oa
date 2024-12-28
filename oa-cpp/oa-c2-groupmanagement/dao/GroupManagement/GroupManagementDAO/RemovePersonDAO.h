#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 26日 星期六 09:37:55 CST
*/
#ifndef _REMOVEPERSON_DAO_
#define _REMOVEPERSON_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/put/OrgGroupPersonlistDO.h"
#include "../../../domain/dto/del/RemovePersonDTO.h"

/**
 * 示例表数据库操作实现
 */
class RemovePersonDAO : public BaseDAO
{
public:
	// 通过个人成员标识xpersonList删除数据
	int deleteByXgroup_Xperson(const string& group_person);
};
#endif // !_REMOVEPERSON_DAO_
