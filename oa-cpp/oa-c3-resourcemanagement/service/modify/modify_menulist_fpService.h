#pragma once
#ifndef _MODIFY_MENULIST_FPSERVICE_
#define _MODIFY_MENULIST_FPSERVICE_

#include <list>
#include "../../domain/dto/modify/modify_menulist_fpDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class modify_menulist_fpService
{
public:

	// �޸�����
	bool updateData(const modify_menulist_fpDTO::Wrapper& dto);

};
#endif // !_MODIFY_MENU_FPSERVICE_
