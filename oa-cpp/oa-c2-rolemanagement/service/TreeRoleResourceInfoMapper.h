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
		// ����������ݶ���
		auto res = make_shared<RoleResourceInfoDTO>();
		// ����㼶�ṹ����ӳ��
		res->_id(source->getId());
		res->_pid(source->getParentId());
		// ��չ����ӳ��
		res->text = source->getText();
		res->is_button = source->getIs_button();
		res->menu_type = source->getMenu_type();
		return res;
	}
};


#endif // !_TREEROLERESOURCEINFOMAPPER_H_

