#include "stdafx.h"
#include "SelectOrgNameTreeController.h"
#include "dao/OrgNameTreeDAO.h"
#include "service/OrgNameTreeMapper.h"
#include "tree/TreeUtil.h"

OrgNameTreeJsonVO::Wrapper SelectOrgNameTreeController::executeQueryOrgName(const PayloadDTO& payload)
{

	auto vo = OrgNameTreeJsonVO::createShared();

	OrgNameTreeDAO orgnametreedao;
	auto orgList = orgnametreedao.selectAllOrgNameTree();

	// 转换为树形结构
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<OrgNameTreeDO>(orgList, OrgNamerTreeMapper());

	// 将根节点存储到列表中
	for (auto one : res)
	{
		vo->data->push_back(OrgNameTreeDTO::Wrapper(dynamic_pointer_cast<OrgNameTreeDTO>(one), OrgNameTreeDTO::Wrapper::Class::getType()));
	}
	return vo;

}


