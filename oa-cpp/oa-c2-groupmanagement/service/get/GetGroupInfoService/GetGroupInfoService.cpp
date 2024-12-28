#include "GetGroupInfoService.h"



//GetGroupInfoDTO::Wrapper GetGroupInfoService::listAll(const GetGroupInfoQuery::Wrapper& query)
//{	
//	// 构建返回对象
//	auto res = GetGroupInfoDTO::createShared();
//	// 查询数据总条数
//	GetGroupInfoDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return {};
//	}
//
//	// 查询数据
//	list<OrgGroupDO> result = dao.selectByName(query->name);
//	// 将DO转换成DTO
//	for (OrgGroupDO sub : result)
//	{
//		auto dto = GetGroupInfoDTO::createShared();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, xName, id, xId, description, xDescription);
//	}
//	return res;
//}

GetGroupInfoVO::Wrapper GetGroupInfoService::getGroupInfoById(const string groupId)
{
	//构建返回对象
	auto ans = GetGroupInfoVO::createShared();
	//创建dao，查询返回DO
	GetGroupInfoDAO dao;
	list<OrgGroupDO> result = dao.selectById(groupId);
	// 直接将DO转换成VO
	for (OrgGroupDO sub : result)
	{
		// 填充数据
		ans->name = sub.getxName();
		ans->id = sub.getxId();
		ans->description = sub.getxDescription();

		//cout << "name:" << (string)ans->name << endl;
		//cout << "id:" << (string)ans->id << endl;
		//cout << "description:" << (string)ans->description << endl;
	}
	return ans;
}

GetGroupInfoVO::Wrapper GetGroupInfoService::getGroupInfoByName(const string groupName)
{
	//构建返回对象
	auto ans = GetGroupInfoVO::createShared();
	//创建dao，查询返回DO
	GetGroupInfoDAO dao;
	list<OrgGroupDO> result = dao.selectByName(groupName);
	// 直接将DO转换成VO
	for (OrgGroupDO sub : result)
	{
		// 填充数据
		ans->name = sub.getxName();
		ans->id = sub.getxId();
		ans->description = sub.getxDescription();

		//cout << "name:" << (string)ans->name << endl;
		//cout << "id:" << (string)ans->id << endl;
		//cout << "description:" << (string)ans->description << endl;
	}

	// 将DO转换成DTO，再将DTO转换成VO
	//for (const OrgGroupDO& sub : result)
	//{
	//	auto dto = GetGroupInfoDTO::createShared();
	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, id, Id, description, Description);
	//
	//	// 创建VO对象并填充数据
	//	auto vo = GetGroupInfoVO::createShared();
	//	vo->name = dto->name;
	//	vo->id = dto->id;
	//	vo->description = dto->description;
	//
	//	// 可以选择将VO添加到列表或者直接返回第一个VO，根据需求来定
	//	// 如果需要返回列表，ans应该是一个包含多个VO的容器
	//	// 例如：ans->add(vo);
	//}

	return ans;
}

