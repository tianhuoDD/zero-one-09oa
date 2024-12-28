#include "GetGroupInfoService.h"



//GetGroupInfoDTO::Wrapper GetGroupInfoService::listAll(const GetGroupInfoQuery::Wrapper& query)
//{	
//	// �������ض���
//	auto res = GetGroupInfoDTO::createShared();
//	// ��ѯ����������
//	GetGroupInfoDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return {};
//	}
//
//	// ��ѯ����
//	list<OrgGroupDO> result = dao.selectByName(query->name);
//	// ��DOת����DTO
//	for (OrgGroupDO sub : result)
//	{
//		auto dto = GetGroupInfoDTO::createShared();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, xName, id, xId, description, xDescription);
//	}
//	return res;
//}

GetGroupInfoVO::Wrapper GetGroupInfoService::getGroupInfoById(const string groupId)
{
	//�������ض���
	auto ans = GetGroupInfoVO::createShared();
	//����dao����ѯ����DO
	GetGroupInfoDAO dao;
	list<OrgGroupDO> result = dao.selectById(groupId);
	// ֱ�ӽ�DOת����VO
	for (OrgGroupDO sub : result)
	{
		// �������
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
	//�������ض���
	auto ans = GetGroupInfoVO::createShared();
	//����dao����ѯ����DO
	GetGroupInfoDAO dao;
	list<OrgGroupDO> result = dao.selectByName(groupName);
	// ֱ�ӽ�DOת����VO
	for (OrgGroupDO sub : result)
	{
		// �������
		ans->name = sub.getxName();
		ans->id = sub.getxId();
		ans->description = sub.getxDescription();

		//cout << "name:" << (string)ans->name << endl;
		//cout << "id:" << (string)ans->id << endl;
		//cout << "description:" << (string)ans->description << endl;
	}

	// ��DOת����DTO���ٽ�DTOת����VO
	//for (const OrgGroupDO& sub : result)
	//{
	//	auto dto = GetGroupInfoDTO::createShared();
	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, id, Id, description, Description);
	//
	//	// ����VO�����������
	//	auto vo = GetGroupInfoVO::createShared();
	//	vo->name = dto->name;
	//	vo->id = dto->id;
	//	vo->description = dto->description;
	//
	//	// ����ѡ��VO��ӵ��б����ֱ�ӷ��ص�һ��VO��������������
	//	// �����Ҫ�����б�ansӦ����һ���������VO������
	//	// ���磺ans->add(vo);
	//}

	return ans;
}

