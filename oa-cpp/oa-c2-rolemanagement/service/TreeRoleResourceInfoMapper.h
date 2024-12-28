#pragma once

#ifndef _TREEROLERESOURCEINFOMAPPER_H_
#define _TREEROLERESOURCEINFOMAPPER_H_

#include "tree/TreeNodeMapper.h"
#include "../domain/do/get/roleresource/RoleResourceDO.h"
#include "../domain/dto/post/roleresource/RoleResourceInfoDTO.h"
//#include "domain/do/RoleResourceDO.h"
//#include "domain/dto/role-resource/RoleResourceInfoDTO.h"

class TreeRoleResourceInfoMapper : public TreeNodeMapper<RoleResourceDO>
{
public:
	shared_ptr<TreeNode> objectMapper(RoleResourceDO* source) const override
	{
		// 创建结果数据对象
		auto res = make_shared<RoleResourceInfoDTO>();
		// 计算层级结构属性映射
		res->_id(source->getId());
		res->_pid(source->getParentId());
		// 扩展属性映射
		res->text = source->getText();
		res->is_button = source->getIs_button();
		res->menu_type = source->getMenu_type();
		return res;
	}
};


#endif // !_TREEROLERESOURCEINFOMAPPER_H_

