package com.zeroone.star.oaj2sysbasic.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oaj2sysbasic.entity.FormTemplate;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.system.basic.template.FormTemplateDTO;
import com.zeroone.star.project.query.j2.system.basic.template.FormTemplateQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.basic.template.FormTemplateVO;

public interface TemplateService extends IService<FormTemplate> {
    /**
     * 分页查询数据
     * @param query
     * @return
     */
    PageDTO<FormTemplateDTO> listAll(FormTemplateQuery query);

    JsonVO<FormTemplateDTO> updateFormTemplate(FormTemplateDTO formTemplate);

    /**
     * 新增模板
     * */
    void insTemplate(FormTemplateDTO templateDTO);

    void delTemplate(String id);

    FormTemplateVO queryTemplate(String id);
}
