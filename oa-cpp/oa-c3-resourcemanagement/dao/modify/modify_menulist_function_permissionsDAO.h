#pragma once
#ifndef _MODIFY_MENULIST_FUNCTION_PERMISSIONSDAO_
#define _MODIFY_MENULIST_FUNCTION_PERMISSIONSDAO_


#include "BaseDAO.h"
#include "../../domain/do/modify/org_menulistDO.h"

/**
 * 示例表数据库操作实现
 */
class modify_menulist_function_permissionsDAO : public BaseDAO
{
public:
	// 修改数据
	int update(const org_menulistDO& uObj);
};







#endif // !_MODIFY_MENULIST_FUNCTION_PERMISSIONSDAO_
