#include "stdafx.h"
#include "SearchDutyService.h"
#include "dao/OrgManagement/PersonalManagement/SearchDutyDAO.h"

oatpp::List<SearchDutyDTO::Wrapper> SearchDutyService::listAll(const oatpp::String& query)
{
	// 构建返回对象
	
	oatpp::List<SearchDutyDTO::Wrapper> res({});
	//查询职务
	SearchDutyDAO dao;
	list<pair<org_unitdutyDO, org_unitDO>> result = dao.selectDuty(query);
	//将DO转换成DTO
	for (auto sub : result)
	{
		auto dto = SearchDutyDTO::createShared();
		dto->xname = sub.first.getXname();
		dto->xlevelName = sub.second.getXlevelName();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
		res->push_back(dto);
	}
	return res;
}
