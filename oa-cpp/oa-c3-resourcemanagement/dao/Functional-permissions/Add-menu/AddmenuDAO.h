#pragma once
#ifndef _ADDMENU_DAO_
#define _ADDMENU_DAO_
#include "../../../../lib-mysql/include/BaseDAO.h"
//#include "../../domain/do/sample/SampleDO.h"
#include "../../../domain/do/Function-permissions/Org_role_menulistDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class AddmenuDAO : public BaseDAO
{
public:
	
	// ��ҳ��ѯ����
	
	// ͨ�����Ų�ѯ����
	uint64_t selectbyrole_id(const Org_role_menulistDO& iObj);
	// ��������
	uint64_t insert(const Org_role_menulistDO& iObj);
	// �޸�����
	uint64_t selectbypermissions(const Org_role_menulistDO& iObj);
	// ͨ��IDɾ������
	uint64_t selectisexist(const Org_role_menulistDO& iObj);
};
#endif // !_SAMPLE_DAO_