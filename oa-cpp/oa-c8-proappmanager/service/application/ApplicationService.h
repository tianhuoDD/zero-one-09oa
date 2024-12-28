#pragma once
#ifndef _APPLICATION_SERVICE_
#define _APPLICATION_SERVICE_

#include "domain/dto/application/ApplicationDTO.h"
#include "domain/query/application/ApplicationQuery.h"
#include "domain/dto/application/AddApplicationDTO.h"
#include "domain/dto/application/ApplicationIdDTO.h"
#include "domain/dto/application/ApplicationTypesDTO.h"
#include "domain/vo/application/ApplicationTypesVO.h"
#include "domain/vo/application/ApplicationPropertiesVO.h"
#include "domain/dto/application/ApplicationPropertiesDTO.h"

class ApplicationService {
public:
	// ��ҳ��ѯӦ��
	ApplicationPageDTO::Wrapper listAllApplication(const ApplicationQuery::Wrapper& query);
	// ��ȡ����Ӧ������
	std::list<std::string> listAllApplicationName();
	// ���Ӧ��
	ApplicationIdDTO::Wrapper insertApplication(const AddApplicationDTO::Wrapper& dto, const PayloadDTO& payload);
	// ͨ��nameɾ��Ӧ��
	ApplicationIdDTO::Wrapper removeApplication(std::string id);
	// ��ѯӦ������
	ApplicationTypesListVO::Wrapper listAppTypes();
	// ��ѯӦ������
	ApplicationPropertiesDTO::Wrapper listAppProperties(const oatpp::String& id);
	// ��ѯ����Ӧ������
	oatpp::List<AvailableGroupListDTO::Wrapper> listAvailableGroupList(const oatpp::String& appid);
	oatpp::List<AvailableIdentityListDTO::Wrapper> listAvailableIdentityList(const oatpp::String& appid);
	oatpp::List<AvailableUnitListDTO::Wrapper> listAvailableUnitList(const oatpp::String& appid);
	oatpp::List<ControllerListDTO::Wrapper> listControllerList(const oatpp::String& appid);
	// �޸�Ӧ������
	bool modifyAppProperties(const ApplicationPropertiesDTO::Wrapper& dto, const PayloadDTO& payload);

};

#endif // !_APPLICATION_SERVICE_
