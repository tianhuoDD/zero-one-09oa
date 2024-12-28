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
	// 分页查询应用
	ApplicationPageDTO::Wrapper listAllApplication(const ApplicationQuery::Wrapper& query);
	// 获取所有应用名称
	std::list<std::string> listAllApplicationName();
	// 添加应用
	ApplicationIdDTO::Wrapper insertApplication(const AddApplicationDTO::Wrapper& dto, const PayloadDTO& payload);
	// 通过name删除应用
	ApplicationIdDTO::Wrapper removeApplication(std::string id);
	// 查询应用类型
	ApplicationTypesListVO::Wrapper listAppTypes();
	// 查询应用属性
	ApplicationPropertiesDTO::Wrapper listAppProperties(const oatpp::String& id);
	// 查询其他应用属性
	oatpp::List<AvailableGroupListDTO::Wrapper> listAvailableGroupList(const oatpp::String& appid);
	oatpp::List<AvailableIdentityListDTO::Wrapper> listAvailableIdentityList(const oatpp::String& appid);
	oatpp::List<AvailableUnitListDTO::Wrapper> listAvailableUnitList(const oatpp::String& appid);
	oatpp::List<ControllerListDTO::Wrapper> listControllerList(const oatpp::String& appid);
	// 修改应用属性
	bool modifyAppProperties(const ApplicationPropertiesDTO::Wrapper& dto, const PayloadDTO& payload);

};

#endif // !_APPLICATION_SERVICE_
