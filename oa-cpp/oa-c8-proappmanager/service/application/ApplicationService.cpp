#include "stdafx.h"
#include "ApplicationService.h"
#include "jwt/json/json.hpp"
#include "dao/application/ApplicationDAO.h"
#include "domain/do/application/ApplicationDO.h"
#include "domain/do/application/ApplicationNameDO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "dao/form/FormDAO.h"

ApplicationTypesListVO::Wrapper ApplicationService::listAppTypes() {
	// 构建返回对象
	auto lvo = ApplicationTypesListVO::createShared();
	// 查询流程类型及数量
	ApplicationDAO dao;
	auto appTypes = dao.selectAppTypes();
	for (auto sub : appTypes) {
		auto vo = ApplicationTypesVO::createShared();
		vo->xapplicationCategory = sub.getXapplicationCategory();
		vo->xcount = sub.getXcount();
		lvo->addData(vo);
	}
	return lvo;
}

ApplicationPropertiesDTO::Wrapper ApplicationService::listAppProperties(const oatpp::String& id) {
	// 构建返回对象
	auto dto = ApplicationPropertiesDTO::createShared();
	// 查询应用属性
	ApplicationDAO dao;
	auto app = dao.selectAppProperties(id);
	for (auto sub : app) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xicon, Xicon, xalias, Xalias, xapplicationCategory, XapplicationCategory, xcreateTime, XcreateTime, xcreatorPerson, XcreatorPerson, xdescription, Xdescription, xlastUpdatePerson, XlastUpdatePerson, xlastUpdateTime, XlastUpdateTime, xname, Xname, xupdateTime, XupdateTime, xproperties, Xproperties);
		break;
	}

	// 从dto中的xproperties寻找defaultForm和maintenanceIdentity
	string defaultFormId = "";
	if (dto->xproperties) {
		auto propertiesStr = dto->xproperties->c_str();
		nlohmann::json propertiesJson = nlohmann::json::parse(propertiesStr);
		if (propertiesJson.contains("defaultForm")) {
			defaultFormId = propertiesJson["defaultForm"].get<std::string>();
		}
		if (propertiesJson.contains("maintenanceIdentity")) {
			dto->maintenanceIdentity = propertiesJson["maintenanceIdentity"].get<std::string>();
		}
	}


	// 查询默认表单的名称
	if (!defaultFormId.empty()) {
		FormDAO formDao;
		auto subRes = formDao.selectNameById(defaultFormId);
		for (auto sub : subRes) {
			dto->xdefaultForm = sub.getName();
			break;
		}
	}


	// 查询可用分组
	dto->xavailableGroupList = listAvailableGroupList(id);
	// 查询可用身份
	dto->xavailableIdentityList = listAvailableIdentityList(id);
	// 查询可用组织
	dto->xavailableUnitList = listAvailableUnitList(id);
	// 查询管理者
	dto->xcontrollerList = listControllerList(id);
	return dto;
}

oatpp::List<AvailableGroupListDTO::Wrapper> ApplicationService::listAvailableGroupList(const oatpp::String& appid) {
	auto list = oatpp::List<AvailableGroupListDTO::Wrapper>::createShared();
	ApplicationDAO dao;
	auto availableGroupList = dao.selectAvailableGroupList(appid->c_str());
	for (auto sub : availableGroupList) {
		auto dto = AvailableGroupListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xorderColumn, XorderColumn, xavailableGroupList, XavailableGroupList);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<AvailableIdentityListDTO::Wrapper> ApplicationService::listAvailableIdentityList(const oatpp::String& appid) {
	auto list = oatpp::List<AvailableIdentityListDTO::Wrapper>::createShared();
	ApplicationDAO dao;
	auto availableIdentityList = dao.selectAvailableIdentityList(appid->c_str());
	for (auto sub : availableIdentityList) {
		auto dto = AvailableIdentityListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xorderColumn, XorderColumn, xavailableIdentityList, XavailableIdentityList);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<AvailableUnitListDTO::Wrapper> ApplicationService::listAvailableUnitList(const oatpp::String& appid) {
	auto list = oatpp::List<AvailableUnitListDTO::Wrapper>::createShared();
	ApplicationDAO dao;
	auto availableUnitList = dao.selectAvailableUnitList(appid->c_str());
	for (auto sub : availableUnitList) {
		auto dto = AvailableUnitListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xorderColumn, XorderColumn, xavailableUnitList, XavailableUnitList);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<ControllerListDTO::Wrapper> ApplicationService::listControllerList(const oatpp::String& appid) {
	auto list = oatpp::List<ControllerListDTO::Wrapper>::createShared();
	ApplicationDAO dao;
	auto controllerList = dao.selectControllerList(appid->c_str());
	for (auto sub : controllerList) {
		auto dto = ControllerListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xorderColumn, XorderColumn, xcontrollerList, XcontrollerList);
		list->push_back(dto);
	}
	return list;
}

static string getCurrTime() {
	// 获取当前时间:2021-01-01 12:00:00
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char timeStr[20];
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", ltm);
	return string(timeStr);
}

bool ApplicationService::modifyAppProperties(const ApplicationPropertiesDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 组装DO数据
	ApplicationPropertiesDO appData;
	ZO_STAR_DOMAIN_DTO_TO_DO(appData, dto, Xid, xid, Xicon, xicon, Xalias, xalias, XapplicationCategory, xapplicationCategory, Xdescription, xdescription, Xname, xname, Xproperties, xproperties);
	appData.setXlastUpdatePerson(payload.getUsername());
	appData.setXlastUpdateTime(getCurrTime());
	appData.setXupdateTime(getCurrTime());
	bool modifyMain = true;

	// 执行数据修改
	ApplicationDAO dao;
	// 修改properties json
	nlohmann::json propertiesJson;
	if (dto->xproperties) {
		propertiesJson = nlohmann::json::parse(dto->xproperties->c_str());
	}
	if (dto->xdefaultForm != nullptr && !dto->xdefaultForm->empty()) {
		// 把xdefaultForm写入xproperties
		propertiesJson["defaultForm"] = dto->xdefaultForm->c_str();
	}
	// 把mainenanceIdentity写入xproperties
	if (dto->maintenanceIdentity != nullptr && !dto->maintenanceIdentity->empty()) {
		propertiesJson["maintenanceIdentity"] = dto->maintenanceIdentity->c_str();
		// 修改维护人
		modifyMain = false;
		return dao.updateProp(dto->xid->c_str(), propertiesJson.dump()) == 1;
	}
	appData.setXproperties(propertiesJson.dump());

	// 修改可用分组
	if (dto->xavailableGroupList != nullptr && !dto->xavailableGroupList->empty()) {
		modifyMain = false;
		int modifyRes = 0;
		modifyRes += dao.deleteAvailableGroup(dto->xid.getValue(""));
		for (auto& sub : *dto->xavailableGroupList) {
			AvailableGroupListDO groupData;
			//string groupId = "";
			//auto selectRes = dao.selectAvailableGroupId(sub->xavailableGroupList->c_str());
			//if (!selectRes.empty()) {
			//	groupId = selectRes.front().getName();// 这里的getName()是获取的xavailableGroupList,其实是id
			//	groupData.setXavailableGroupList(groupId);
			//	groupData.setXid(dto->xid.getValue(""));
			//	groupData.setXorderColumn(0);
			//	modifyRes += dao.deleteAvailableGroup(dto->xid.getValue(""));
			//	modifyRes += dao.insertAvailableGroup(groupData);
			//	cout << "modify group success." << endl;
			//} else cout << "group list faild." << endl;
			groupData.setXid(dto->xid.getValue(""));
			groupData.setXorderColumn(0);
			groupData.setXavailableGroupList(sub->xavailableGroupList.getValue(""));
			modifyRes += dao.insertAvailableGroup(groupData);
		}
		return modifyRes == 1 || modifyRes == 1 + dto->xavailableGroupList->size();
	}
	// 修改可用身份
	if (dto->xavailableIdentityList != nullptr && !dto->xavailableIdentityList->empty()) {
		modifyMain = false;
		int modifyRes = 0;
		modifyRes += dao.deleteAvailableIdentity(dto->xid.getValue(""));
		for (auto& sub : *dto->xavailableIdentityList) {
			AvailableIdentityListDO identityData;
			//string identityId = "";
			//auto selectRes = dao.selectAvailableIdentityId(sub->xavailableIdentityList->c_str());
			//if (!selectRes.empty()) {
			//	identityId = selectRes.front().getName();// 这里的getName()是获取的xavailableIdentityList,其实是id
			//	identityData.setXavailableIdentityList(identityId);
			//	identityData.setXid(dto->xid.getValue(""));
			//	identityData.setXorderColumn(0);
			//	modifyRes += dao.deleteAvailableIdentity(dto->xid.getValue(""));
			//	modifyRes += dao.insertAvailableIdentity(identityData);
			//	cout << "modify identity success." << endl;
			//} else cout << "identity list faild." << endl;
			identityData.setXid(dto->xid.getValue(""));
			identityData.setXorderColumn(0);
			identityData.setXavailableIdentityList(sub->xavailableIdentityList.getValue(""));
			modifyRes += dao.insertAvailableIdentity(identityData);
		}
		return modifyRes == 1 || modifyRes == 1 + dto->xavailableIdentityList->size();
	}
	// 修改可用组织
	if (dto->xavailableUnitList != nullptr && !dto->xavailableUnitList->empty()) {
		modifyMain = false;
		int modifyRes = 0;
		modifyRes += dao.deleteAvailableUnit(dto->xid.getValue(""));
		for (auto& sub : *dto->xavailableUnitList) {
			AvailableUnitListDO unitData;
			//string unitId = "";
			//auto selectRes = dao.selectAvailableUnitId(sub->xavailableUnitList->c_str());
			//if (!selectRes.empty()) {
			//	unitId = selectRes.front().getName();// 这里的getName()是获取的xavailableUnitList,其实是id
			//	unitData.setXavailableUnitList(unitId);
			//	unitData.setXid(dto->xid.getValue(""));
			//	unitData.setXorderColumn(0);
			//	modifyRes += dao.deleteAvailableUnit(dto->xid.getValue(""));
			//	modifyRes += dao.insertAvailableUnit(unitData);
			//	cout << "modify unit success." << endl;
			//} else cout << "unit list faild." << endl;
			unitData.setXid(dto->xid.getValue(""));
			unitData.setXorderColumn(0);
			unitData.setXavailableUnitList(sub->xavailableUnitList.getValue(""));
			modifyRes += dao.insertAvailableUnit(unitData);
		}
		return modifyRes == 1 || modifyRes == 1 + dto->xavailableUnitList->size();
	}
	// 修改管理者
	if (dto->xcontrollerList != nullptr && !dto->xcontrollerList->empty()) {
		modifyMain = false;
		int modifyRes = 0;
		modifyRes += dao.deleteController(dto->xid.getValue(""));
		for (auto& sub : *dto->xcontrollerList) {
			ControllerListDO controllerData;
			//string controllerId = "";
			//auto selectRes = dao.selectControllerId(sub->xcontrollerList->c_str());
			//if (!selectRes.empty()) {
			//	controllerId = selectRes.front().getName();// 这里的getName()是获取的xcontrollerList,其实是id
			//	controllerData.setXcontrollerList(controllerId);
			//	controllerData.setXid(dto->xid.getValue(""));
			//	controllerData.setXorderColumn(0);
			//	modifyRes += dao.deleteController(dto->xid.getValue(""));
			//	modifyRes += dao.insertController(controllerData);
			//	cout << "modify controller success." << endl;
			//} else cout << "controller list faild." << endl;
			controllerData.setXid(dto->xid.getValue(""));
			controllerData.setXorderColumn(0);
			controllerData.setXcontrollerList(sub->xcontrollerList.getValue(""));
			modifyRes += dao.insertController(controllerData);
		}
		return modifyRes == 1 || modifyRes == 1 + dto->xcontrollerList->size();
	}
	if (modifyMain) {
		return dao.updateAppProperties(appData) == 1;
	}

	return false;
}

ApplicationPageDTO::Wrapper ApplicationService::listAllApplication(const ApplicationQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = ApplicationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ApplicationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ApplicationDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ApplicationDO sub : result) {
		auto dto = ApplicationDTO::createShared();
		//	sql << "SELECT xname,xalias,xapplicationCategory ,xdescription,xid,xcreateTime,xsequence,xupdateTime,xdistributeFactor,\
			xcreatorPerson,xicon,xiconHue,xlastUpdatePerson,\
			xlastUpdateTime,xproperties FROM pp_e_application";
		//f1 dto字段名 f2 do字段名 target->f1=src.get##f2();
		 //ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xname, Name, xalias, Alias, xapplicationCategory, ApplicationCategory
			, xid, Id, xcreateTime, CreateTime, xsequence, Sequence, xupdateTime, UpdateTime, xdistributeFactor, DistributeFactor)
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xcreatorPerson, CreatorPerson, xdescription, Description, xlastUpdatePerson, LastUpdatePerson,
				xlastUpdateTime, LastUpdateTime, xproperties, Properties, xicon, Icon, xiconHue, IconHue)
			pages->addData(dto);

	}
	return pages;
}

std::list<std::string> ApplicationService::listAllApplicationName() {
	std::list<std::string> names;
	ApplicationDAO  dao;
	list<ApplicationNameDO> result = dao.selectApplicationName();
	for (ApplicationNameDO sub : result) {
		names.push_back(sub.getName());
	}
	return names;
}

ApplicationIdDTO::Wrapper ApplicationService::insertApplication(const AddApplicationDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto iddto = ApplicationIdDTO::createShared();
	ApplicationDO data;
	//生成ID
	SnowFlake sf(8, 9);
	uint64_t num = 0;
	while (1) {
		num = sf.nextId();
		if (num > 0)
			break;
	}
	std::string id = to_string(num);
	data.setId(id);
	//生成CreateTime = UpdateTime = LastUpdateTime
	std::string ctf = SimpleDateTimeFormat().format();
	data.setCreateTime(ctf);
	data.setUpdateTime(ctf);
	data.setLastUpdateTime(ctf);
	//生成CreatorPerson
	data.setCreatorPerson(payload.getUsername());
	//生成LastUpdatePerson
	data.setLastUpdatePerson(payload.getUsername());
	//生成Sequence
	std::string date = ctf.substr(0, 10);
	std::string time = ctf.substr(11, 8);
	date.erase(4, 1).erase(6, 1);
	time.erase(2, 1).erase(4, 1);
	std::string ct = date + time;
	data.setSequence(ct.append(id));

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, xname, Alias, xalias, ApplicationCategory, xapplicationCategory, Description, xdescription);
	//data.setDistributeFactor(0);
	//data.setIcon(std::string("null"));
	//data.setIconHue(std::string("null"));
	data.setProperties(std::string("{}"));
	ApplicationDAO dao;
	int row = dao.insert(data);
	if (row == 0) {
		iddto->id = id;
	} else {
		iddto->id = "";
	}
	return iddto;
}

ApplicationIdDTO::Wrapper ApplicationService::removeApplication(std::string id) {
	auto data = ApplicationIdDTO::createShared();
	ApplicationDAO dao;
	uint64_t row = dao.deleteById(id);
	if (row == 1) {
		data->id = id;
	} else {
		data->id = "";
	}
	return data;
}

