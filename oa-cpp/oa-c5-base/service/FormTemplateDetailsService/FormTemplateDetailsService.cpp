#include "FormTemplateDetailsService.h"
#include "../../dao/FormTemplateDetails/FormTemplateDetailsDAO.h"


FormTemplateDetailsDTO::Wrapper FormTemplateDetailsService::listFormInfo(const char* xid)
{
	// �������ض���
	auto dto = FormTemplateDetailsDTO::createShared();

	// ��ѯ����
	FormTemplateDetailsDAO dao;
	list<formTemplateBuiltDO> result = dao.selectInfoById(xid);

	// ��DOת��DTO
	for (formTemplateBuiltDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xcreateTime, CreateTime, xsequence, Sequence, xupdateTime, UpdateTime, xdistributeFactor, DistributeFactor, xalias, Alias, xcategory, Category, xdata, Data, xdescription, Description, xicon, Icon, xmobileData, MobileData, xname, Name, xoutline, Outline)
	}

	// ����
	return dto;
}

oatpp::List<FormTemplateCategoryDTO::Wrapper> FormTemplateDetailsService::listCategory(const char* xid)
{
	// �������ض���
	oatpp::List<FormTemplateCategoryDTO::Wrapper> data = oatpp::List<FormTemplateCategoryDTO::Wrapper>::createShared();
	//��ѯ���༰������
	FormTemplateDetailsDAO DAO;
	list<formTemplateBuiltDO> result = DAO.selectcategoryAndnumByApp(xid);

	// ��DOת����VO
	for (formTemplateBuiltDO sub : result)
	{
		auto dto = FormTemplateCategoryDTO::createShared();
		dto->xcategory = sub.getCategory();
		dto->xnum = sub.getNum();
		data->push_back(dto);
	}
	return data;
}
