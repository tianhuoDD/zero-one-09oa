#pragma once
#ifndef _CONFIGURATIONDAO_
#define _CONFIGURATIONDAO_
#include "BaseDAO.h"
#include"../../../domain/do/configuration/atq/ConfigurationDO.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class ConfigurationDAO : public BaseDAO
{
public:
	// ͨ�������ʶ��ѯ����
	list<ConfigurationDO> selectById(const string& id);
	// ��������
	int insert(const ConfigurationDO& iObj);
	// �޸�����
	int update(const ConfigurationDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // !_SAMPLE_DAO_
