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
	// ��ȡ��ǰʱ��:2021-01-01 12:00:00
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

// ���ݱ�汾
static void backupFormVersion(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload, const string& formId) {
	FormDO formData;
	formData.setForm(formId);
	ZO_STAR_DOMAIN_DTO_TO_DO(formData, dto, Data, data);
	string idStr = generateId();
	formData.setId(idStr);
	// ��ȡ��ǰʱ�䣬��Ϊ����ʱ��
	string timeStr = getCurrTime();
	formData.setCreateTime(timeStr);
	formData.setUpdateTime(timeStr);
	// �ô���ʱ���idStrƴ�ӳ����к�
	string serialNumber = getCurrTimeWithMillis() + idStr;
	formData.setSequence(serialNumber);
	formData.setPerson(payload.getUsername());
	// ִ���������
	FormDAO dao;
	dao.insertToFormVersion(formData);
}

string FormService::saveForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ��װDO����
	FormDO formData;
	ZO_STAR_DOMAIN_DTO_TO_DO(formData, dto, Alias, alias, Application, application, Data, data, HasMobile, hasMobile, Icon, icon, Id, id, MobileData, mobileData, Name, name, Category, category, Description, description);
	formData.setLastUpdatePerson(payload.getUsername());
	// ִ���������
	FormDAO dao;
	// ��������
	string idStr = generateId();
	formData.setId(idStr);

	// ��ȡ��ǰʱ�䣬��Ϊ����ʱ��
	string timeStr = getCurrTime();
	formData.setCreateTime(timeStr);
	formData.setUpdateTime(timeStr);
	formData.setLastUpdateTime(timeStr);

    // �ô���ʱ���idStrƴ�ӳ����к�
    string serialNumber = getCurrTimeWithMillis() + idStr;
    formData.setSequence(serialNumber);

	if (dto->alias->empty()) {	// �������Ϊ�գ���ʹ��name��Ϊ����
		formData.setAlias(dto->name);
	}
	//if (dto->icon->empty()) {	// ���ͼ��Ϊ�գ���ʹ��Ĭ��ͼ��
	//	formData.setIcon("default");
	//}
	
	// ִ���������
	if (dao.insertToForm(formData) == 1) {
		backupFormVersion(dto, payload, idStr);
		return idStr;
	}
	return string("�������ܳ�������");
}

bool FormService::updateForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload) {
	backupFormVersion(dto, payload, dto->id.getValue({}));
	// ��װDO����
	FormDO formData;
	ZO_STAR_DOMAIN_DTO_TO_DO(formData, dto, Alias, alias, Data, data, HasMobile, hasMobile, Icon, icon, MobileData, mobileData, Name, name, Id, id, Category, category, Description, description);
	formData.setLastUpdatePerson(payload.getUsername());
	// ��ȡ��ǰʱ�䣬��Ϊ����޸�ʱ��
	formData.setLastUpdateTime(getCurrTime());
	formData.setUpdateTime(getCurrTime());
	formData.setLastUpdatePerson(payload.getUsername());

	// ִ�������޸�
	FormDAO dao;
	// ���ݱ�汾

	return dao.update(formData) == 1;
}

bool FormService::deleteForm(const oatpp::String& id) {
	// ִ������ɾ��
	FormDAO dao;
	if (dao.deleteById(id) == 1) {
		dao.deleteVersionByFormId(id);
		return true;
	}
	return false;
}

// ��ѯ�������������
oatpp::List<FormCategoryDTO::Wrapper> FormService::listCategory(const char* xapplication)
{
	// �������ض���
	oatpp::List<FormCategoryDTO::Wrapper> data = oatpp::List<FormCategoryDTO::Wrapper>::createShared();
	//��ѯ���༰������
	FormDAO DAO;
	list<FormDO> result = DAO.selectcategoryAndnumByApp(xapplication);

	// ��DOת����VO
	for (FormDO sub : result)
	{
		auto dto = FormCategoryDTO::createShared();
		dto->xcategory = sub.getCategory();
		dto->xnum = sub.getNum();
		data->push_back(dto);
	}
	return data;
}

// ��ҳ��ѯ���б�
FormListPageDTO::Wrapper FormService::listAllForm(const FormListQuery::Wrapper& userQuery)
{
	// �������ض���
	auto pages = FormListPageDTO::createShared();
	pages->pageIndex = userQuery->pageIndex;
	pages->pageSize = userQuery->pageSize;


	// ��ѯ����������
	FormDAO dao;
	uint64_t count = dao.count(userQuery);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<FormDO> result = dao.selectFormWithPage(userQuery);
	// ��DOת����DTO
	for (FormDO sub : result)
	{
		auto dto = FormListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xname, Name, xcategory, Category,xalias,Alias, xdescription, Description, xapplication, Application ,xcreateTime, CreateTime, xupdateTime, UpdateTime, xlastUpdatePerson, LastUpdatePerson, xlastUpdateTime, LastUpdateTime, xhasMobile, HasMobile,xicon,Icon)
		pages->addData(dto);
	}
	return pages;
}


// ��ѯ������
FormInfoDTO::Wrapper FormService::listFormInfo(const char* xid)
{
	// �������ض���
	auto dto = FormInfoDTO::createShared();

	// ��ѯ����
	FormDAO dao;
	list<FormDO> result = dao.selectInfoById(xid);

	// ��DOת��DTO
	for (FormDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xname, Name, xcategory, Category, xalias, Alias, xdescription, Description, xapplication, Application, xcreateTime, CreateTime, xupdateTime, UpdateTime, xlastUpdatePerson, LastUpdatePerson, xlastUpdateTime, LastUpdateTime, xhasMobile, HasMobile, xproperties, Properties, xmobileData, MobileData,xdata,Data, xicon, Icon)
	}

	// ����
	return dto;
}
