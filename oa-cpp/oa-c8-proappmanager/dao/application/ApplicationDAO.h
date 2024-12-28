#pragma once
#ifndef _APPLICATION_DAO_
#define _APPLICATION_DAO_

#include "BaseDAO.h"
#include <list>
#include "domain/do/application/ApplicationTypesDO.h"
#include "domain/do/application/ApplicationPropertiesDO.h"
#include "domain/query/application/ApplicationQuery.h"
#include "domain/do/application/ApplicationDO.h"
#include "domain/do/application/ApplicationNameDO.h"

class ApplicationDAO : public BaseDAO {
public:
	// ͳ����������
	uint64_t count(const ApplicationQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ApplicationDO> selectWithPage(const ApplicationQuery::Wrapper& query);
	// ��ѯ����Ӧ������
	list<ApplicationNameDO> selectApplicationName();
	// ��������
	uint64_t insert(const ApplicationDO& iObj);
	// ͨ��nameɾ������
	uint64_t deleteById(std::string id);
	// ��ѯӦ������
	list<ApplicationTypesDO> selectAppTypes();
	// ��ѯӦ������
	list<ApplicationPropertiesDO> selectAppProperties(const string& id);
	// ��ѯ����Ӧ������
	list<AvailableGroupListDO> selectAvailableGroupList(const string& appid);
	list<AvailableIdentityListDO> selectAvailableIdentityList(const string& appid);
	list<AvailableUnitListDO> selectAvailableUnitList(const string& appid);
	list<ControllerListDO> selectControllerList(const string& appid);

	// �޸�Ӧ������
	int updateAppProperties(const ApplicationPropertiesDO& obj);
	// ���ӿ������
	int insertAvailableIdentity(const AvailableIdentityListDO& obj);
	// ���ӿ�����֯
	int insertAvailableGroup(const AvailableGroupListDO& obj);
	// ���ӹ�����
	int insertController(const ControllerListDO& obj);
	// ���ӿ�����֯
	int insertAvailableUnit(const AvailableUnitListDO& obj);
	// �������ֲ�ѯ������ݶ�Ӧ��id
	list<ApplicationNameDO> selectAvailableIdentityId(const string& identityName);
	// �������ֲ�ѯ������֯��Ӧ��id
	list<ApplicationNameDO> selectAvailableGroupId(const string& groupName);
	// �������ֲ�ѯ���õ�Ԫ��Ӧ��id
	list<ApplicationNameDO> selectAvailableUnitId(const string& unitName);
	// �������ֲ�ѯ�����߶�Ӧ��id
	list<ApplicationNameDO> selectControllerId(const string& controllerName);

	// ɾ���������
	int deleteAvailableIdentity(const string& appId);
	// ɾ��������֯
	int deleteAvailableGroup(const string& appId);
	// ɾ��������
	int deleteController(const string& appId);
	// ɾ��������֯
	int deleteAvailableUnit(const string& appId);
	// �޸�����
	int updateProp(const string& appId, const string& propJson);
};

#endif // !_APPLICATION_DAO_