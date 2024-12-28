#include "stdafx.h"
#include "DataDetailService.h"
#include "dao/data/DataDetailDAO.h"

DataDetailDTO::Wrapper DataDetailService::listOne(const std::string& dataid) {
	// 构建返回对象
	auto resdto = DataDetailDTO::createShared();

	//查询数据详情
	DataDetailDAO dao;
	auto result = dao.selectByAppIdAndDataId(dataid);

	// 将 DO 转换成 DTO
	for (const auto& sub : result) {
		// 使用宏进行字段映射
		ZO_STAR_DOMAIN_DO_TO_DTO(resdto, sub, appid, Application, dataid, DataId, name, Name, alias, Alias, description, Description, createTime, CreateTime, updateTime, UpdateTime);
		break;
	}
	// 查询data数据
	auto resultData = dao.selectData(dataid);
	for (const auto& sub : resultData) {
		resdto->data = sub.getFieldStr();
		break;
	}
	return resdto;
}
