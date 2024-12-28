#pragma once

#ifndef _RESOURCETREE_DAO_
#define _RESOURCETREE_DAO_

#include "BaseDAO.h"
#include <list>
#include "../../domain/do/menuinfo/MenuInfoDO.h"
#include "ResourceMapper.h"

class ResourcetreeDAO :public BaseDAO
{
public:
    // Method to fetch all menu information from the database
    std::list<MenuInfoDO> getAllMenuInfo();
};
#endif