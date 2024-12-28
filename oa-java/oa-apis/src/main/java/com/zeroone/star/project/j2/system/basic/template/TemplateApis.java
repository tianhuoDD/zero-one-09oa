package com.zeroone.star.project.j2.system.basic.template;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.system.basic.template.FormTemplateDTO;
import com.zeroone.star.project.query.j2.system.basic.template.FormTemplateQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.basic.template.FormTemplateVO;

public interface TemplateApis {

    /**
     * 获取表单详情
     * */
    JsonVO<FormTemplateVO>queryTemplate(String id);


    /**
     * 删除表单
     *
     * */
    JsonVO<Boolean>delTemplate(String id);
    /**
     * 查询所有模版
     * @param query
     * @return
     */
    JsonVO<PageDTO<FormTemplateDTO>> queryAll(FormTemplateQuery query);



    JsonVO<FormTemplateDTO> updateFormTemplate(FormTemplateDTO formTemplateDTO);

    /**
     * 新增表单模板
     * */
    JsonVO<Boolean>insTemplate(FormTemplateDTO templateDTO);

}
