#pragma once

#ifndef _ORGRESMENUDO_H_
#define _ORGRESMENUDO_H_

#include "../../DoInclude.h"

class OrgResMenuDO
{
	//菜单id
	CC_SYNTHESIZE(string, menu_id, Menu_id);
	// 菜单名称
	CC_SYNTHESIZE(string, menu_name, Menu_name);
	// 菜单的类型(1为普通菜单2为目录3为内嵌iFrame4为外链跳转)
	CC_SYNTHESIZE(string, menu_type, Menu_type);
	// 父菜单id
	CC_SYNTHESIZE(string, parent_id, Parent_id);
	// 是否按钮
	CC_SYNTHESIZE(string, is_button, Is_button);
	// 权限标志
	CC_SYNTHESIZE(string, permission, Permission);
	// 菜单状态（1启用  0停用）
	CC_SYNTHESIZE(string, status, Status);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 创建者id
	CC_SYNTHESIZE(string, creator_id, Creator_id);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//更新者id
	CC_SYNTHESIZE(string, updater_id, Updater_id);
	//更新时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	//逻辑删除
	CC_SYNTHESIZE(string, deleted, Deleted);


public:
	OrgResMenuDO(){}
	OrgResMenuDO(string menuID, string menuName, uint16_t menuType, string parentId, uint8_t isButton,
		string permission, uint16_t status, string remark, string creatorId, string createTime, 
		string updaterId,string updateTime, uint8_t deleted)
	{
		this->menu_id = menuID;
		this->menu_name = menuName;
		this->menu_type = menuType;
		this->parent_id = parentId;
		this->is_button = isButton;
		this->permission = permission;
		this->status = status;
		this->remark = remark;
		this->creator_id = creatorId;
		this->create_time = createTime;
		this->updater_id = updaterId;
		this->update_time = updateTime;
		this->deleted = deleted;

	}
};


#endif // !_ORGRESMENUDO_H_
