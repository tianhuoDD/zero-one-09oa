#pragma once
#ifndef _MODIFY_MENULIST_FUNCTION_PERMISSIONSDAO_
#define _MODIFY_MENULIST_FUNCTION_PERMISSIONSDAO_


#include "BaseDAO.h"
#include "../../domain/do/modify/org_menulistDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class modify_menulist_function_permissionsDAO : public BaseDAO
{
public:
	// �޸�����
	int update(const org_menulistDO& uObj);
};







#endif // !_MODIFY_MENULIST_FUNCTION_PERMISSIONSDAO_
