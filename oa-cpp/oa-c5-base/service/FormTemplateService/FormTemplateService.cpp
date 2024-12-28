#include "stdafx.h"
#include "FormTemplateService.h"
#include "../../dao/FormTemplate/FormTemplateDAO.h"


FormTemplatePageDTO::Wrapper FormTemplateService::listAll(const FormTemplateQuery::Wrapper& query)
{
    // 构建返回对象
    auto pages = FormTemplatePageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    FormTemlplateDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    list<formTemplateBuiltDO> result = dao.selectWithPage(query);
    // 将DO转换成DTO
    for (formTemplateBuiltDO sub : result)
    {
        auto dto = FormTemplateDTO::createShared();
        // 假设FormTemplateDTO中的属性与formTemplateBuiltDO中的属性名相同
        // 如果不同，需要根据实际的属性名进行调整
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xcreateTime, CreateTime, xupdateTime, UpdateTime, xicon, Icon, xname, Name)
            pages->addData(dto);
    }
    return pages;
}
