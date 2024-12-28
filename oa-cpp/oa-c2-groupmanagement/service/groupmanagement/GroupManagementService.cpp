//
// Created by asd on 2024/10/23.
//
#include "GroupManagementService.h"

#include <domain/vo/BaseJsonVO.h>

#include "dao/GroupManagement/GroupManagementDAO.h"

bool GroupManagementService::delGroupMember(const DelGroupMemberDTO::Wrapper& dto) {
	GroupManagementDAO dao;
	return dao.delByGroupIdList(dto) > 0;
}

bool GroupManagementService::delUnitMember(const DelUnitMemberDTO::Wrapper& dto) {
	GroupManagementDAO dao;
	return dao.delByUnitIdList(dto) > 0;
}

AddGroupMemberJsonVO::Wrapper GroupManagementService::addGroupMember
(const AddGroupMemberReqDTO::Wrapper& dto) {
	string groupId = dto->gruopId;

	//先根据id查出它从属的群组id列表
	GroupManagementDAO dao;
	auto groupList = dao.queryGroupIdListByGroupId(dto->gruopId);
	list<string> groupIdList;
	for (auto& item : groupList) {
		if (item == groupId) {
			//不能添加自己的组id到自己的群组成员列表中
			return nullptr;
		}
		//将org-group-groupList的groupList字段取出来
		groupIdList.emplace_back(item);
	}

	//第二步是处理群组id列表，
	//如果存在就添加，如果本来不存在 新列表中存在就添加，
	//如果本来存在，但是新列表不存在，那就删除
	//用set提取出数据，方便查找
	std::unordered_set<string> set1(groupIdList.begin(), groupIdList.end());
	std::unordered_set<string> set2(dto->groupList->begin(), dto->groupList->end());

	//用来处理新增和删除的数据
	list<string> addIdList;
	list<string> delIdList;

	// 找出链表2中 不在链表1中的元素，放入“新增数据”链表
	for (auto& it : set2) {
		if (set1.find(it) == set1.end()) {
			addIdList.emplace_back(it);
		}
	}
	// 找出链表1中 不在链表2中的元素，放入“删除数据”链表
	for (auto& it : set1) {
		if (set2.find(it) == set2.end()) {
			delIdList.emplace_back(it);
		}
	}
	if (dao.addGroupIdList(groupId, addIdList, delIdList) == 0) {
		//更新失败
		return nullptr;
	}

	//第三步，select出所有的群组名称，返回给前端
	auto retList = AddGroupMemberJsonVO::createShared();
	auto ret = dao.queryGroupNameByGroupIdList(groupId);
	for (auto it : ret) {
		auto resp = AddGroupMemberRespDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(resp, it, groupId, xId, groupName, xName, distinguishedName, xDistinguishedName);
		retList->addData(resp);
	}

	return retList;
}

AddUnitMemberJsonVO::Wrapper GroupManagementService::addUnitMember(
	const AddUnitMemberReqDTO::Wrapper& dto) {

	string groupId = dto->gruopId;
	//先根据id查出它从属的群组id列表
	GroupManagementDAO dao;
	auto unitList = dao.queryUnitIdListByGroupId(dto->gruopId);
	list<string> unitIdList;
	for (auto& item : unitList) {
		//将org-group-groupList的groupList字段取出来
		unitIdList.emplace_back(item);
	}

	//第二步是处理群组id列表，
	//如果存在就添加，如果本来不存在 新列表中存在就添加，
	//如果本来存在，但是新列表不存在，那就删除
	//用set提取出数据，方便查找
	std::unordered_set<string> set1(unitIdList.begin(), unitIdList.end());
	std::unordered_set<string> set2(dto->unitList->begin(), dto->unitList->end());

	//用来处理新增和删除的数据
	list<string> addIdList;
	list<string> delIdList;
	// 找出链表2中 不在链表1中的元素，放入“新增数据”链表
	for (auto& it : set2) {
		if (set1.find(it) == set1.end()) {
			addIdList.emplace_back(it);
		}
	}
	// 找出链表1中 不在链表2中的元素，放入“删除数据”链表
	for (auto& it : set1) {
		if (set2.find(it) == set2.end()) {
			delIdList.emplace_back(it);
		}
	}
	if (dao.addUnitIdList(groupId, addIdList, delIdList) == 0) {
		//更新失败
		return nullptr;
	}

	//第三步，select出所有的群组名称，返回给前端
	auto retList = AddUnitMemberJsonVO::createShared();
	auto ret = dao.queryUnitNameByUnitIdList(groupId);
	for (auto it : ret) {
		auto resp = AddUnitMemberRespDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(resp, it, unitId, xid, unitName, xname, levelName, xlevelName);
		retList->addData(resp);
	}

	return retList;
}
