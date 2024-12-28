#pragma once
#ifndef _MODIFY_MENULIST_FPSERVICE_
#define _MODIFY_MENULIST_FPSERVICE_

#include <list>
#include "../../domain/dto/modify/modify_menulist_fpDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class modify_menulist_fpService
{
public:

	// 修改数据
	bool updateData(const modify_menulist_fpDTO::Wrapper& dto);

};
#endif // !_MODIFY_MENU_FPSERVICE_
