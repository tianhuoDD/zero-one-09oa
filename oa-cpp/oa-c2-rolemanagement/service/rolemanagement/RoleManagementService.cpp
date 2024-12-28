#include "RoleManagementService.h"

#include"dao/rolemanagement/RoleManagementDAO.h"
#include"domain/do/get/personlist/OrgRolePersonListDO.h"
#include"SimpleDateTimeFormat.h"
#include<ctime>

PersonListPageDTO::Wrapper RoleManagementService::listAll(const PersonListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PersonListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RoleManagementDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OrgRolePersonListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (OrgRolePersonListDO sub : result)
	{
		auto dto = PersonListDTO::createShared();
		dto->name = sub.getXName();
		dto->employee = sub.getXEmployee();
		dto->phone = sub.getXMobile();
		dto->mailbox = sub.getXMail();
		dto->xpersonList = sub.getXid();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age);
		pages->addData(dto);

	}
	return pages;
}

bool RoleManagementService::updateData(const UpdateRoleDTO::Wrapper& dto)
{
	RoleManagementDAO dao;
	//查看是否唯一
	if (dto->newxunique.getValue("") != dto->last_xunique.getValue(""))
	{
		int r = dao.roleUnique(dto->newxunique.getValue(""));
		//重复
		if (r > 0)return false;
	}


	// 组装DO数据
	OrgRoleDO data;
	// 执行数据修改
	data.setXName(dto->xname.getValue(""));
	data.setXUnique(dto->newxunique.getValue(""));
	data.setXDescription(dto->xdescription.getValue(""));
	data.setLastXUnique(dto->last_xunique.getValue(""));
	data.setXUpdateTime(SimpleDateTimeFormat::format());
	//时间戳应该是创建时的
	//data.setXorderNumber(time(NULL));
	//auto str = dto-
	//xdistinguishedName  日期(纯数字，把-:什么的删掉)+xid
	// xname@xunique@R
	data.setXDistinguishedName(dto->xname.getValue("") + "@" + dto->newxunique.getValue("") + "@R");
	//拼音
	//RoleManagementDAO dao;
	return dao.update(data) == 1;
}


//bool RoleManagementService::updateData(const UpdateRoleDTO::Wrapper& dto)
//{// 组装DO数据
//	OrgRoleDO data;
//	//下方的语句报错
//	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, XName, xname, XUnique, xunique, XDescription, xdescription, LastXUnique, lastxunique);
//		// 执行数据修改
//	data.setXName(dto->xname.getValue(""));
//	data.setXUnique(dto->xunique.getValue(""));
//	data.setXDescription(dto->xdescription.getValue(""));
//	data.setLastXUnique(dto->last_xunique.getValue(""));
//	data.setXUpdateTime(SimpleDateTimeFormat::format());
//	data.setXorderNumber(time(NULL));
//	//auto str = dto-
//	//xdistinguishedName  日期(纯数字，把-:什么的删掉)+xid
//	//拼音
//	RoleManagementDAO dao;
//	return dao.update(data) == 1;
//}
//



uint64_t RoleManagementService::saveGroupMember(const GroupMemberDTO::Wrapper& idList)
{
	OrgRoleGroupListDO data;
	RoleManagementDAO dao;
	auto groupList = idList->idList.get();
	auto roleId = idList->roleId.get();

	list<oatpp::String> datagroupList = dao.selectGroupList(*roleId);	
	//_______________________________________
	// 创建 groupList 的副本（去重前）
	auto originalGroupList = *groupList;

	// 使用 datagroupList 对 groupList 进行去重
	for (const auto& item : datagroupList) {
		groupList->remove_if([&item](const oatpp::String& groupItem) {
			return groupItem == item;
			});
	}

	// 使用 originalGroupList 对 datagroupList 进行去重
	for (const auto& item : originalGroupList) {
		datagroupList.remove_if([&item](const oatpp::String& dataItem) {
			return dataItem == item;
			});
	}
	//_______________________________________

	/*
		uint64_t maxOrderColumn = 0;
	uint64_t count = 0;

	std::list<OrgResRoleMenuDO> listData;
	maxOrderColumn = dao.selectMaxXordercolumn(roleId, "org_res_role_menu", "role_id") + 1;
	uint32_t i = 0;
	for (const auto item : *menuList)
	{
		data.setRole_id(roleId);
		data.setMenuList(item);
		data.setXorderColumn(maxOrderColumn+i);
		i++;
		listData.push_back(data);
	}

	count += dao.deleteOrgResRoleMenu(roleId, dataMenuList, listData);
	
	*/
	uint64_t maxOrderColumn = 0;
	uint64_t count = 0;
	std::list<OrgRoleGroupListDO> listData;
	maxOrderColumn = dao.selectMaxXordercolumn(*roleId,"org_role_grouplist","ROLE_XID") + 1;
	uint32_t i = 0;
	for (const auto item : *groupList)
	{
		std::cout << item.getValue({}) << std::endl;
		//std::cout << maxOrderColumn << std::endl;
		data.setROLE_XID(*roleId);
		data.setXgroupList(item);
		data.setXorderColumn(maxOrderColumn+i);
		i++;
		listData.push_back(data);
	}
	count += dao.updateOrgRoleGroupList(*roleId, datagroupList,listData);
	return count;
	/*for (const auto item : datagroupList)
	{
		maxOrderColumn = dao.selectMaxXordercolumn(*roleId, "org_role_grouplist", "ROLE_XID");
		if (dao.deleteOrgRoleGroupList(*roleId, item, maxOrderColumn) == oatpp::data::mapping::type::UInt64(-1))
		{
			return -1;
		}
		else
		{
			count++;
		}  
	}*/
}

uint64_t RoleManagementService::removeGroupMember(const GroupMemberDTO::Wrapper& idList)
{
	RoleManagementDAO dao;
	auto groupList = idList->idList.get();
	auto roleId = idList->roleId.get();
	uint64_t count = 0;
	count += dao.deleteOrgRoleGroupListOperation(*roleId, *groupList);
	return count;
}

void RoleManagementService::listRoleMenu(const std::string& roleId, const RoleResourceJsonVO::Wrapper& vo)
{
	RoleManagementDAO dao;
	list<oatpp::String> dataMenuList = dao.selectMenuList(roleId);
	auto listRoleResource = dao.selectRoleResource(dataMenuList);

	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<RoleResourceDO>(listRoleResource, TreeRoleResourceInfoMapper());

	for (auto one : res)
	{
		vo->data->push_back(RoleResourceInfoDTO::Wrapper(dynamic_pointer_cast<RoleResourceInfoDTO>(one), RoleResourceInfoDTO::Wrapper::Class::getType()));
	}
}

uint64_t RoleManagementService::updateRoleResource(const RoleResourceListDTO::Wrapper& roleResource)
{
	OrgResRoleMenuDO data;
	RoleManagementDAO dao;
	auto menuList = roleResource->idList.get();
	auto roleId = roleResource->roleId.getValue({});

	list<oatpp::String> dataMenuList = dao.selectMenuList(roleId);
	//----------------------------
	// 创建 menuList 的副本（去重前）
	auto originalMenuList = *menuList;

	// 使用 dataMenuList 对 menuList 进行去重
	for (const auto& item : dataMenuList) {
		menuList->remove_if([&item](const oatpp::String& groupItem) {
			return groupItem == item;
			});
	}

	// 使用 originalMenuList 对 dataMenuList 进行去重
	for (const auto& item : originalMenuList) {
		dataMenuList.remove_if([&item](const oatpp::String& dataItem) {
			return dataItem == item;
			});
	}
	//----------------------------
	uint64_t maxOrderColumn = 0;
	uint64_t count = 0;

	std::list<OrgResRoleMenuDO> listData;
	maxOrderColumn = dao.selectMaxXordercolumn(roleId, "org_res_role_menu", "role_id") + 1;
	uint32_t i = 0;
	for (const auto item : *menuList)
	{
		data.setRole_id(roleId);
		data.setMenuList(item);
		data.setXorderColumn(maxOrderColumn+i);
		i++;
		listData.push_back(data);
	}

	count += dao.deleteOrgResRoleMenu(roleId, dataMenuList, listData);
	
	return count;
}
