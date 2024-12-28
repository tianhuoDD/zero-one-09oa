#include "stdafx.h"
#include "FormService.h"
#include "../../dao/form/FormDAO.h"
#include <list>
#include "SnowFlake.h"
#include <chrono>

static string getCurrTimeWithMillis() {
	auto now = std::chrono::system_clock::now();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	time_t now_c = std::chrono::system_clock::to_time_t(now);
	tm* ltm = localtime(&now_c);
	char timeStr[24];
	strftime(timeStr, sizeof(timeStr), "%Y%m%d%H%M%S", ltm);
	snprintf(timeStr + 14, sizeof(timeStr) - 14, "%03d", static_cast<int>(millis.count()));
	return string(timeStr);
}

static string getCurrTime() {
	// 获取当前时间:2021-01-01 12:00:00
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char timeStr[20];
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", ltm);
	return string(timeStr);
}

static string generateId() {
	SnowFlake sf(8, 4);
	uint64_t id;
	do {
		id = sf.nextId();
	} while (id == 0);
	return to_string(id);
}

// 备份表版本
static void backupFormVersion(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload, const string& formId) {
	FormDO formData;
	formData.setForm(formId);
	ZO_STAR_DOMAIN_DTO_TO_DO(formData, dto, Data, data);
	string idStr = generateId();
	formData.setId(idStr);
	// 获取当前时间，作为创建时间
	string timeStr = getCurrTime();
	formData.setCreateTime(timeStr);
	formData.setUpdateTime(timeStr);
	// 用创建时间和idStr拼接成序列号
	string serialNumber = getCurrTimeWithMillis() + idStr;
	formData.setSequence(serialNumber);
	formData.setPerson(payload.getUsername());
	// 执行数据添加
	FormDAO dao;
	dao.insertToFormVersion(formData);
}

string FormService::saveForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 组装DO数据
	FormDO formData;
	ZO_STAR_DOMAIN_DTO_TO_DO(formData, dto, Alias, alias, Application, application, Data, data, HasMobile, hasMobile, Icon, icon, Id, id, MobileData, mobileData, Name, name, Category, category, Description, description);
	formData.setLastUpdatePerson(payload.getUsername());
	// 执行数据添加
	FormDAO dao;
	// 创建数据
	string idStr = generateId();
	formData.setId(idStr);

	// 获取当前时间，作为创建时间
	string timeStr = getCurrTime();
	formData.setCreateTime(timeStr);
	formData.setUpdateTime(timeStr);
	formData.setLastUpdateTime(timeStr);

    // 用创建时间和idStr拼接成序列号
    string serialNumber = getCurrTimeWithMillis() + idStr;
    formData.setSequence(serialNumber);

	if (dto->alias->empty()) {	// 如果别名为空，则使用name作为别名
		formData.setAlias(dto->name);
	}
	//if (dto->icon->empty()) {	// 如果图标为空，则使用默认图标
	//	formData.setIcon("default");
	//}
	
	// 执行数据添加
	if (dao.insertToForm(formData) == 1) {
		backupFormVersion(dto, payload, idStr);
		return idStr;
	}
	return string("操作可能出现问题");
}

bool FormService::updateForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload) {
	backupFormVersion(dto, payload, dto->id.getValue({}));
	// 组装DO数据
	FormDO formData;
	ZO_STAR_DOMAIN_DTO_TO_DO(formData, dto, Alias, alias, Data, data, HasMobile, hasMobile, Icon, icon, MobileData, mobileData, Name, name, Id, id, Category, category, Description, description);
	formData.setLastUpdatePerson(payload.getUsername());
	// 获取当前时间，作为最后修改时间
	formData.setLastUpdateTime(getCurrTime());
	formData.setUpdateTime(getCurrTime());
	formData.setLastUpdatePerson(payload.getUsername());

	// 执行数据修改
	FormDAO dao;
	// 备份表版本

	return dao.update(formData) == 1;
}

bool FormService::deleteForm(const oatpp::String& id) {
	// 执行数据删除
	FormDAO dao;
	if (dao.deleteById(id) == 1) {
		dao.deleteVersionByFormId(id);
		return true;
	}
	return false;
}

// 查询所有类别及其数量
oatpp::List<FormCategoryDTO::Wrapper> FormService::listCategory(const char* xapplication)
{
	// 构建返回对象
	oatpp::List<FormCategoryDTO::Wrapper> data = oatpp::List<FormCategoryDTO::Wrapper>::createShared();
	//查询分类及其数量
	FormDAO DAO;
	list<FormDO> result = DAO.selectcategoryAndnumByApp(xapplication);

	// 将DO转换成VO
	for (FormDO sub : result)
	{
		auto dto = FormCategoryDTO::createShared();
		dto->xcategory = sub.getCategory();
		dto->xnum = sub.getNum();
		data->push_back(dto);
	}
	return data;
}

// 分页查询所有表单
FormListPageDTO::Wrapper FormService::listAllForm(const FormListQuery::Wrapper& userQuery)
{
	// 构建返回对象
	auto pages = FormListPageDTO::createShared();
	pages->pageIndex = userQuery->pageIndex;
	pages->pageSize = userQuery->pageSize;


	// 查询数据总条数
	FormDAO dao;
	uint64_t count = dao.count(userQuery);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<FormDO> result = dao.selectFormWithPage(userQuery);
	// 将DO转换成DTO
	for (FormDO sub : result)
	{
		auto dto = FormListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xname, Name, xcategory, Category,xalias,Alias, xdescription, Description, xapplication, Application ,xcreateTime, CreateTime, xupdateTime, UpdateTime, xlastUpdatePerson, LastUpdatePerson, xlastUpdateTime, LastUpdateTime, xhasMobile, HasMobile,xicon,Icon)
		pages->addData(dto);
	}
	return pages;
}


// 查询表单详情
FormInfoDTO::Wrapper FormService::listFormInfo(const char* xid)
{
	// 构建返回对象
	auto dto = FormInfoDTO::createShared();

	// 查询数据
	FormDAO dao;
	list<FormDO> result = dao.selectInfoById(xid);

	// 将DO转成DTO
	for (FormDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xname, Name, xcategory, Category, xalias, Alias, xdescription, Description, xapplication, Application, xcreateTime, CreateTime, xupdateTime, UpdateTime, xlastUpdatePerson, LastUpdatePerson, xlastUpdateTime, LastUpdateTime, xhasMobile, HasMobile, xproperties, Properties, xmobileData, MobileData,xdata,Data, xicon, Icon)
	}

	// 返回
	return dto;
}
