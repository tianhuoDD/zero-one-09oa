#pragma once
#ifndef _DELETEMENU_DAO_
#define _DELETEMENU_DAO_
#include "BaseDAO.h"
#include "../../../domain/dto/Functional-permissions/Delete-menu/DeletemenuDTO.h"
#include "../../../domain/do/Function-permissions/Org_role_menulistDO.h"
#include "../../../domain/vo/Functional-permissions/Delete-menu/DeletemenuVO.h"
//#include "../../domain/do/sample/SampleDO.h"
//#include "../../../domain/do/Function-permissions/Add-me"
//#include "../../domain/query/sample/SampleQuery.h"

/**
 * 示例表数据库操作实现
 */
class DeletemenuDAO : public BaseDAO
{
public:
	uint64_t selectbyall(const Org_role_menulistDO& iObj);
	// 通过ID删除数据
	uint64_t deleteById(const Org_role_menulistDO&iObj);
};
#endif // !_SAMPLE_DAO_
