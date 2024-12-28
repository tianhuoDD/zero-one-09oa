#include "stdafx.h"
#include "ResourcetreeDAO.h"
#include "../../service/resource-tree-permissios/ResourcetreeMapper.h"
#include <sstream>

std::list<MenuInfoDO> ResourcetreeDAO::getAllMenuInfo() {
    stringstream sql;
    sql << "SELECT menu_id, menu_name, parent_id, menu_type, is_button, level, link_url, icon FROM org_menu";

    ResourcetreeMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<MenuInfoDO, ResourcetreeMapper>(sqlStr, mapper);
}
