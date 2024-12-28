#include"stdafx.h"
#include"service/rolemanagement/RoleManagementService/put/PersonMember/PersonMemberService.h"
#include"dao/put/PersonMember/PersonMemberDAO.h"
#include"SimpleDateTimeFormat.h"
#include<ctime>
#include<list>

uint64_t PersonMemberService::saveData(const PersonMemberDTO::Wrapper& dto)
{
#if 0
	// 组装DO数据
	PersonMemberDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ROLE_XID, role_xid);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, XgroupList, xgroupList);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, XorderColumn, xorderColumn);

	// 执行数据添加
	PersonMemberDAO dao;
	return dao.insert(data);
#else
	PersonMemberDO data;
	PersonMemberDAO dao;
	auto xpersonList = dto->xpersonList.get();
	auto role_xid = dto->role_xid.get();
	list<oatpp::String> datapersonList = dao.selectPersonMemberList(*role_xid);
	//_______________________________________
	// 创建 groupList 的副本（去重前）
	auto originalPersonList = *xpersonList;

	// 使用 datagroupList 对 groupList 进行去重
	for (const auto& item : datapersonList) {
		xpersonList->remove_if([&item](const oatpp::String& groupItem) {
			return groupItem == item;
			});
	}


	// 使用 originalGroupList 对 datagroupList 进行去重
	for (const auto& item : originalPersonList) {
		datapersonList.remove_if([&item](const oatpp::String& dataItem) {
			return dataItem == item;
			});
	}
	uint64_t maxOrderColumn = 0;
	uint64_t count = 0;
	std::list<PersonMemberDO> listData;
	maxOrderColumn = dao.selectMaxXordercolumn(*role_xid, "org_role_personlist", "ROLE_XID") + 1;
	uint32_t i = 0;
	for (const auto item : *xpersonList)
	{
		std::cout << item.getValue({}) << std::endl;
		//std::cout << maxOrderColumn << std::endl;
		data.setROLE_XID(*role_xid);
		data.setXpersonList(item);
		data.setXorderColumn(maxOrderColumn + i);
		i++;
		listData.push_back(data);
	}
	count += dao.updatePersonMemberList(*role_xid, datapersonList, listData);
	return count;

#endif

}

uint64_t PersonMemberService::removePersonMember(const PersonMemberDTO::Wrapper& xpersonList)
{
	PersonMemberDAO dao;
	auto role_xid = xpersonList->role_xid.get();
	auto personList = xpersonList->xpersonList.get();
	uint64_t count = 0;
	count += dao.deletePersonMemberListOperation(*role_xid, *personList);
	return count;
}