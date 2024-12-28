#include "stdafx.h"
#include "DataDetailService.h"
#include "dao/data/DataDetailDAO.h"

DataDetailDTO::Wrapper DataDetailService::listOne(const std::string& dataid) {
	// �������ض���
	auto resdto = DataDetailDTO::createShared();

	//��ѯ��������
	DataDetailDAO dao;
	auto result = dao.selectByAppIdAndDataId(dataid);

	// �� DO ת���� DTO
	for (const auto& sub : result) {
		// ʹ�ú�����ֶ�ӳ��
		ZO_STAR_DOMAIN_DO_TO_DTO(resdto, sub, appid, Application, dataid, DataId, name, Name, alias, Alias, description, Description, createTime, CreateTime, updateTime, UpdateTime);
		break;
	}
	// ��ѯdata����
	auto resultData = dao.selectData(dataid);
	for (const auto& sub : resultData) {
		resdto->data = sub.getFieldStr();
		break;
	}
	return resdto;
}
