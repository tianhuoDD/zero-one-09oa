#include "stdafx.h"
#include "ConfigurationService.h"
#include "../../../dao/configuration/atq/ConfigurationDAO.h"


ConfigurationPageDTO::Wrapper ConfigurationService::listAll(string id)
{
	// �������ض���
	auto pages = ConfigurationPageDTO::createShared();
	//��ѯ����
	ConfigurationDAO dao;
	list<ConfigurationDO>result = dao.selectById(id);
	// ��DOת����DTO
	for (ConfigurationDO sub : result) {
		auto dto = ConfigurationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xcreatorUnitName, XcreatorUnitName, xappId, XappId, xalias, Xalias, xdocumentType, XdocumentType, xsendNotify, XsendNotify, process, Process, range, Range, xcreatorPerson, XcreatorPerson, xmanagePerson, XmanagePerson)
			pages->addData(dto);
	}
	return pages;
}

int ConfigurationService::saveData(const ConfigurationDTO::Wrapper& dto)
{
	// ��װDO����
	ConfigurationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, XcreatorUnitName, xcreatorUnitName,XappId, xappId,Xalias, xalias,XdocumentType, xdocumentType, XsendNotify, xsendNotify, Process, process, Range, range, XcreatorPerson, xcreatorPerson, XmanagePerson, xmanagePerson)
	// ִ���������
	ConfigurationDAO dao;
	return dao.insert(data);
}

bool ConfigurationService::updateData(const ConfigurationDTO::Wrapper& dto)
{
	// ��װDO����
	ConfigurationDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, XcreatorUnitName, xcreatorUnitName, XappId, xappId, Xalias, xalias, XdocumentType, xdocumentType, XsendNotify, xsendNotify, Process, process, Range, range, XcreatorPerson, xcreatorPerson, XmanagePerson, xmanagePerson)
		// ִ�������޸�
	ConfigurationDAO dao;
	return dao.update(data) == 1;
}

bool ConfigurationService::removeData(string id)
{
	ConfigurationDAO dao;
	return dao.deleteById(id) == 1;
}