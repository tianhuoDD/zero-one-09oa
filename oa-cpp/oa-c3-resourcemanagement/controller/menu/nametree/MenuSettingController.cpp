#include "stdafx.h"
#include "MenuSettingController.h"
#include "domain/do/menuinfo/MenuInfoDO.h"
#include "dao/menu/nametree/MenuInfoDAO.h"
#include "../../../service/menu/nametree/MenuInfoService.h"

#include "tree/TreeUtil.h"
#include "service/menu/nametree/TreeMenuMapper.h"

MyMenuInfoJsonVO::Wrapper MenuSettingController::execMenuInfo(const MyMenuInfoQuery::Wrapper& query, const PayloadDTO& payload) {/*, const PayloadDTO& payload*/
	auto vo = MyMenuInfoJsonVO::createShared();
	// 构建返回对象
	auto pages = MyMenuInfoDTO::createShared();
	//pages->pageIndex = query->pageIndex;
	//pages->pageSize = query->pageSize;
	// 查询数据总条数
	MenuInfoDAO dao;
	//uint64_t count = dao.count(query);
	//if (count <= 0)
	//{
	//	return vo;
	//}
	//// 分页查询数据
	//pages->total = count;
	//pages->calcPages();

	list<MenuInfoDO> listData = dao.selectWithPage(query);
	//list<MenuInfoDO> listData;
	//// 创建模拟菜单数据（此数据应来源于数据库）
	//listData.push_back(MenuInfoDO("1", u8"系统管理", "", 0));
	//listData.push_back(MenuInfoDO("2", u8"用户管理", "1", 1));
	//listData.push_back(MenuInfoDO("3", u8"角色管理", "1", 1));
	//listData.push_back(MenuInfoDO("4", u8"菜单管理", "1", 1));
	//listData.push_back(MenuInfoDO("5", u8"订单管理", "", 0));
	//listData.push_back(MenuInfoDO("6", u8"入库订单", "5", 1));
	//listData.push_back(MenuInfoDO("7", u8"出库订单", "5", 1));
	//listData.push_back(MenuInfoDO("8", u8"销售订单", "5", 1));
	//listData.push_back(MenuInfoDO("9", u8"订单统计", "8", 2));
	//listData.push_back(MenuInfoDO("10", u8"订单报表","8", 2));

	// 转换为树形结构
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<MenuInfoDO>(listData, TreeMenuMapper());
	// 将根节点存储到列表中
	for (auto one : res)
	{
		vo->data->push_back(MyMenuInfoDTO::Wrapper(dynamic_pointer_cast<MyMenuInfoDTO>(one), MyMenuInfoDTO::Wrapper::Class::getType()));
	}
	return vo;
}