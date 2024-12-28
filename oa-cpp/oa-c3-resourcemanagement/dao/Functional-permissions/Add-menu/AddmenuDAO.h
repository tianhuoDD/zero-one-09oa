#pragma once
#ifndef _ADDMENU_DAO_
#define _ADDMENU_DAO_
#include "../../../../lib-mysql/include/BaseDAO.h"
//#include "../../domain/do/sample/SampleDO.h"
#include "../../../domain/do/Function-permissions/Org_role_menulistDO.h"


/**
 * 示例表数据库操作实现
 */
class AddmenuDAO : public BaseDAO
{
public:
	
	// 分页查询数据
	
	// 通过工号查询数据
	uint64_t selectbyrole_id(const Org_role_menulistDO& iObj);
	// 插入数据
	uint64_t insert(const Org_role_menulistDO& iObj);
	// 修改数据
	uint64_t selectbypermissions(const Org_role_menulistDO& iObj);
	// 通过ID删除数据
	uint64_t selectisexist(const Org_role_menulistDO& iObj);
};
#endif // !_SAMPLE_DAO_