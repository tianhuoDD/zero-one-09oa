#pragma once
#ifndef _ORGROLEMENULIST_DO_
#define _ORGROLEMENULIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class Org_role_menulistDO
{
	// ��ɫ����
	CC_SYNTHESIZE(string, role_id, role_Id);
	//�˵�Ȩ��
	CC_SYNTHESIZE(string, menulist,Menulist);
	// �����(��ѡ)
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
public:
	Org_role_menulistDO() {
		role_id = "";
		menulist = "";
		xorderColumn = 0;
	}
};

#endif // 