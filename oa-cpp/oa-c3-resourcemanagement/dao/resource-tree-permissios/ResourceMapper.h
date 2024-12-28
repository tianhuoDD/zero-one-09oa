#pragma once

#include "tree/TreeNodeMapper.h"
#include "domain/do/menuinfo/MenuInfoDO.h"
#include "domain/dto/resource-tree-permissios/ResourcetreeDTO.h"

/**
 * ӳ��˵������ֶ�
 */
class ResourceMapper : public TreeNodeMapper<MenuInfoDO> {
public:
    shared_ptr<TreeNode> objectMapper(MenuInfoDO* source) const override {
        auto res = make_shared<ResourcetreeDTO>();

        // ӳ���ֶ�
        res->menu_id = source->getMenu_Id();
        res->menu_name = source->getMenu_Name();
        res->parent_id = source->getParent_Id();
        res->menu_type = source->getMenu_Type();
        res->is_button = source->getIs_Button();
        res->level = source->getLevel();
        res->link_url = source->getLink_Url();
        res->icon = source->getIcon();

        return res;
    }
};
