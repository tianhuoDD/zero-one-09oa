#include "stdafx.h"
#include "ResourcetreeController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "domain/do/menuinfo/MenuInfoDO.h"
#include "service/resource-tree-permissios/ResourcetreeMapper.h"
#include "tree/TreeUtil.h"

PermissionsJsonVO::Wrapper ResourcetreeController::executeQuerypermissions(const PayloadDTO& payload)
{
    // 定义一个JsonVO对象
    auto vo = PermissionsJsonVO::createShared();
    ResourcetreeDAO dao;
    // 创建模拟菜单数据（此数据应来源于数据库）
    std::list<MenuInfoDO> listData = dao.getAllMenuInfo();
    //listData.push_back(MenuInfoDO("1", u8"xitong guanli", 1, 0, "", "sys:manage", 1, 1, "/sm", "xitong guanli", "admin", "2023-02-17", "admin", "2023-02-17"));
    //listData.push_back(MenuInfoDO("2", u8"yonghu guanli", 1, 0, "1", "user:manage", 1, 2, "/sm/um", "yonghu guanli", "admin", "2023-02-17", "admin", "2023-02-17"));
    //listData.push_back(MenuInfoDO("3", u8"juese guanli", 1, 0, "1", "role:manage", 1, 2, "/sm/rm", "juese guanli", "admin", "2023-02-17", "admin", "2023-02-17"));
    //listData.push_back(MenuInfoDO("4", u8"caidan guanli", 1, 0, "1", "menu:manage", 1, 2, "/sm/mm", "caidan guanli", "admin", "2023-02-17", "admin", "2023-02-17"));
    //listData.push_back(MenuInfoDO("5", u8"dingdan guanli", 1, 0, "", "order:manage", 1, 1, "/om", "dingdan guanli", "admin", "2023-02-17", "admin", "2023-02-17"));
    //listData.push_back(MenuInfoDO("6", u8"ruku dingdan", 1, 0, "5", "order:in", 1, 2, "/om/em", "ruku dingdan", "admin", "2023-02-17", "admin", "2023-02-17"));
    //listData.push_back(MenuInfoDO("7", u8"chuku dingdan", 1, 0, "5", "order:out", 1, 2, "/om/om", "chuku dingdan", "admin", "2023-02-17", "admin", "2023-02-17"));
    //listData.push_back(MenuInfoDO("8", u8"xiaoshou dingdan", 1, 0, "5", "order:sale", 1, 2, "/om/sm", "xiaoshou dingdan", "admin", "2023-02-17", "admin", "2023-02-17"));
    //listData.push_back(MenuInfoDO("9", u8"dingdan tongji", 1, 0, "8", "order:stat", 1, 3, "/om/sm/t1", "dingdan tongji", "admin", "2023-02-17", "admin", "2023-02-17"));
    //listData.push_back(MenuInfoDO("10", u8"dingdan baobiao", 1, 0, "8", "order:report", 1, 3, "/om/sm/t2", "dingdan baobiao", "admin", "2023-02-17", "admin", "2023-02-17"));

    // 将数据转换为树形结构
    std::list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<MenuInfoDO>(listData, TreeResourceMapper());

    // 将根节点存储到列表中
    for (auto one : res) {
        vo->data->push_back(ResourcetreeDTO::Wrapper(dynamic_pointer_cast<ResourcetreeDTO>(one), ResourcetreeDTO::Wrapper::Class::getType()));
    }

    return vo;
}
