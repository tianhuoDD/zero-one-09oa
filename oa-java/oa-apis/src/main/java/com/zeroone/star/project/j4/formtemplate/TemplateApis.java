package com.zeroone.star.project.j4.formtemplate;

import com.zeroone.star.project.dto.j4.formtemplate.AddTemplateDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.formtemplate.AddTemplateVO;
import com.zeroone.star.project.vo.j4.formtemplate.QueryTemplateVO;

/**
 * 表单模版相关设置接口
 */
public interface TemplateApis {
    /**
     * 新增表单模版设置通过id查询
     */
        JsonVO<AddTemplateVO>AddTemplateVOById(AddTemplateDTO addTemplateDTO);
    /**
     * 新增表单模版通过种类查询
     */
    JsonVO<AddTemplateVO>AddTemplateVO(String xcategory);
    /**
     * 查询表单模版
     */
    JsonVO<QueryTemplateVO>QueryTemplateVO(String xid);
}
