#include "stdafx.h"
#include "MenuSettingController.h"
#include "domain/do/menuinfo/MenuInfoDO.h"
#include "dao/menu/nametree/MenuInfoDAO.h"
#include "../../../service/menu/nametree/MenuInfoService.h"

#include "tree/TreeUtil.h"
#include "service/menu/nametree/TreeMenuMapper.h"

MyMenuInfoJsonVO::Wrapper MenuSettingController::execMenuInfo(const MyMenuInfoQuery::Wrapper& query, const PayloadDTO& payload) {/*, const PayloadDTO& payload*/
	auto vo = MyMenuInfoJsonVO::createShared();
	// �������ض���
	auto pages = MyMenuInfoDTO::createShared();
	//pages->pageIndex = query->pageIndex;
	//pages->pageSize = query->pageSize;
	// ��ѯ����������
	MenuInfoDAO dao;
	//uint64_t count = dao.count(query);
	//if (count <= 0)
	//{
	//	return vo;
	//}
	//// ��ҳ��ѯ����
	//pages->total = count;
	//pages->calcPages();

	list<MenuInfoDO> listData = dao.selectWithPage(query);
	//list<MenuInfoDO> listData;
	//// ����ģ��˵����ݣ�������Ӧ��Դ�����ݿ⣩
	//listData.push_back(MenuInfoDO("1", u8"ϵͳ����", "", 0));
	//listData.push_back(MenuInfoDO("2", u8"�û�����", "1", 1));
	//listData.push_back(MenuInfoDO("3", u8"��ɫ����", "1", 1));
	//listData.push_back(MenuInfoDO("4", u8"�˵�����", "1", 1));
	//listData.push_back(MenuInfoDO("5", u8"��������", "", 0));
	//listData.push_back(MenuInfoDO("6", u8"��ⶩ��", "5", 1));
	//listData.push_back(MenuInfoDO("7", u8"���ⶩ��", "5", 1));
	//listData.push_back(MenuInfoDO("8", u8"���۶���", "5", 1));
	//listData.push_back(MenuInfoDO("9", u8"����ͳ��", "8", 2));
	//listData.push_back(MenuInfoDO("10", u8"��������","8", 2));

	// ת��Ϊ���νṹ
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<MenuInfoDO>(listData, TreeMenuMapper());
	// �����ڵ�洢���б���
	for (auto one : res)
	{
		vo->data->push_back(MyMenuInfoDTO::Wrapper(dynamic_pointer_cast<MyMenuInfoDTO>(one), MyMenuInfoDTO::Wrapper::Class::getType()));
	}
	return vo;
}