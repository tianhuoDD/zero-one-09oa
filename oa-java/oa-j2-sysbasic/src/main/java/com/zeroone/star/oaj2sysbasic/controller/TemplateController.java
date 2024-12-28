package com.zeroone.star.oaj2sysbasic.controller;

import com.zeroone.star.oaj2sysbasic.service.TemplateService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.system.basic.template.FormTemplateDTO;
import com.zeroone.star.project.j2.system.basic.template.TemplateApis;
import com.zeroone.star.project.query.j2.system.basic.template.FormTemplateQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.basic.template.FormTemplateVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("sysbasic/template-setting")
@Api(tags = "表单模板设置")
@Validated
public class TemplateController implements TemplateApis {
    /*@Resource
    //TemplateService templateService;
    */
    @Autowired
    TemplateService templateService;

    @GetMapping("query-all")
    @ApiOperation(value = "分页查询所有")
    @Override
    public JsonVO<PageDTO<FormTemplateDTO>> queryAll(@Validated FormTemplateQuery query) {
        return JsonVO.success(templateService.listAll(query));
    }

    @Override
    @ApiOperation(value = "修改表单模板")
    @PostMapping("update")
    public JsonVO<FormTemplateDTO> updateFormTemplate(FormTemplateDTO formTemplateDTO) {
        return templateService.updateFormTemplate(formTemplateDTO);
    }

    /**
     * 新增表单模板
     */
    @Override
    @PostMapping("/template-info")
    @ApiOperation(value = "新增表单模板")
    public JsonVO<Boolean> insTemplate(FormTemplateDTO templateDTO) {
        templateService.insTemplate(templateDTO);

        return  JsonVO.success(new Boolean(true));
    }

    /**
     * 删除表单模板
     */
    @DeleteMapping("/template-info")
    @ApiOperation(value = "删除表单模板")
    public JsonVO<Boolean> delTemplate(String id) {
        templateService.delTemplate(id);
        return JsonVO.success(new Boolean(true));
    }

    /**
     * 获取表单详情
     */
    @GetMapping("/template-info")
    @ApiOperation(value = "获取表单模板详情")
    public JsonVO<FormTemplateVO> queryTemplate(String id) {
        FormTemplateVO formTemplateVO=templateService.queryTemplate(id);
        return JsonVO.success(formTemplateVO);
    }
}
