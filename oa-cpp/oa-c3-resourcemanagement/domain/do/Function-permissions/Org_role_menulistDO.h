#pragma once
#ifndef _ORGROLEMENULIST_DO_
#define _ORGROLEMENULIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class Org_role_menulistDO
{
	// 角色工号
	CC_SYNTHESIZE(string, role_id, role_Id);
	//菜单权限
	CC_SYNTHESIZE(string, menulist,Menulist);
	// 排序号(可选)
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
public:
	Org_role_menulistDO() {
		role_id = "";
		menulist = "";
		xorderColumn = 0;
	}
};

#endif // 