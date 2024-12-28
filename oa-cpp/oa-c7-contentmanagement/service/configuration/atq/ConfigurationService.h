#pragma once
#ifndef _CONFIGURATIONSERVICE_
#define _CONFIGURATIONSERVICE_
#include <list>
#include "domain/vo/configuration/atq/configurationVo.h"
#include "domain/dto/configuration/atq/configurationDto.h"
#include "../../../dao/configuration/atq/ConfigurationDAO.h"
#include "../../../dao/configuration/atq/ConfigurationMapper.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ConfigurationService
{
public:
	//��ѯ����
	ConfigurationPageDTO::Wrapper listAll(string id);
	// ��������
	int saveData(const ConfigurationDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ConfigurationDTO::Wrapper& dto);
	// ͨ�����ʶɾ������
	bool removeData(string id);
};

#endif // 

