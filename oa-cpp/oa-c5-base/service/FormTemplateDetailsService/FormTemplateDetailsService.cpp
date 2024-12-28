#include "FormTemplateDetailsService.h"
#include "../../dao/FormTemplateDetails/FormTemplateDetailsDAO.h"


FormTemplateDetailsDTO::Wrapper FormTemplateDetailsService::listFormInfo(const char* xid)
{
	// 构建返回对象
	auto dto = FormTemplateDetailsDTO::createShared();

	// 查询数据
	FormTemplateDetailsDAO dao;
	list<formTemplateBuiltDO> result = dao.selectInfoById(xid);

	// 将DO转成DTO
	for (formTemplateBuiltDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xcreateTime, CreateTime, xsequence, Sequence, xupdateTime, UpdateTime, xdistributeFactor, DistributeFactor, xalias, Alias, xcategory, Category, xdata, Data, xdescription, Description, xicon, Icon, xmobileData, MobileData, xname, Name, xoutline, Outline)
	}

	// 返回
	return dto;
}

oatpp::List<FormTemplateCategoryDTO::Wrapper> FormTemplateDetailsService::listCategory(const char* xid)
{
	// 构建返回对象
	oatpp::List<FormTemplateCategoryDTO::Wrapper> data = oatpp::List<FormTemplateCategoryDTO::Wrapper>::createShared();
	//查询分类及其数量
	FormTemplateDetailsDAO DAO;
	list<formTemplateBuiltDO> result = DAO.selectcategoryAndnumByApp(xid);

	// 将DO转换成VO
	for (formTemplateBuiltDO sub : result)
	{
		auto dto = FormTemplateCategoryDTO::createShared();
		dto->xcategory = sub.getCategory();
		dto->xnum = sub.getNum();
		data->push_back(dto);
	}
	return data;
}
