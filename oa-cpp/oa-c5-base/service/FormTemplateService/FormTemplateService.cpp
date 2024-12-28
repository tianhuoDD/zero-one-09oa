#include "stdafx.h"
#include "FormTemplateService.h"
#include "../../dao/FormTemplate/FormTemplateDAO.h"


FormTemplatePageDTO::Wrapper FormTemplateService::listAll(const FormTemplateQuery::Wrapper& query)
{
    // �������ض���
    auto pages = FormTemplatePageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // ��ѯ����������
    FormTemlplateDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // ��ҳ��ѯ����
    pages->total = count;
    pages->calcPages();
    list<formTemplateBuiltDO> result = dao.selectWithPage(query);
    // ��DOת����DTO
    for (formTemplateBuiltDO sub : result)
    {
        auto dto = FormTemplateDTO::createShared();
        // ����FormTemplateDTO�е�������formTemplateBuiltDO�е���������ͬ
        // �����ͬ����Ҫ����ʵ�ʵ����������е���
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xcreateTime, CreateTime, xupdateTime, UpdateTime, xicon, Icon, xname, Name)
            pages->addData(dto);
    }
    return pages;
}
