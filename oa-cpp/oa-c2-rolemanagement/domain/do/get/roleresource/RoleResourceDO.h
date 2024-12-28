#pragma once

#ifndef _ROLERESOURCEDO_H_
#define _ROLERESOURCEDO_H_

//#include "../DoInclude.h"
#include "../../DoInclude.h"		

class RoleResourceDO
{
	//资源id
	CC_SYNTHESIZE(string, id, Id);
	// 资源文本描述
	CC_SYNTHESIZE(string, text, Text);
	// 图标描述
	CC_SYNTHESIZE(uint32_t, is_button, Is_button);
	// 菜单类型
	CC_SYNTHESIZE(uint32_t, menu_type, Menu_type);
	// 父节点ID  子资源
	CC_SYNTHESIZE(string, parentId, ParentId);

public:
	RoleResourceDO(){}
	RoleResourceDO(string id, string text, uint32_t Is_button, uint32_t Menu_type, string parentId)
	{
		this->id = id;
		this->text = text;
		this->is_button = Is_button;
		this->menu_type = Menu_type;
		this->parentId = parentId;
	}
};






#endif // !_ROLERESOURCEDO_H_
