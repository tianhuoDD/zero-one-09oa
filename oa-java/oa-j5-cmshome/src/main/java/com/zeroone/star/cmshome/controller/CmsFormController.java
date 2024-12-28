package com.zeroone.star.cmshome.controller;


import com.zeroone.star.cmshome.service.impl.CmsFormServiceImpl;
import com.zeroone.star.project.j5.cmshome.DocumentFormApis;
import com.zeroone.star.project.dto.j5.cmshome.DocumentDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.form.DocumentFormVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author huangfeifan
 * @since 2024-10-29
 */
@RestController
@RequestMapping("/cmshome/cms-form")
@Api(tags = "获取消息表单和数据")
@Validated
public class CmsFormController implements DocumentFormApis {

    @Resource
    private CmsFormServiceImpl cmsFormService;

    @GetMapping("query-form-by-id")
    @ApiOperation(value = "获取消息表单")
    @Override
    public JsonVO<DocumentFormVO> queryById(String xid) {
        return JsonVO.success(cmsFormService.getDocumentFormById(xid));
    }

    @GetMapping("query-document-by-id")
    @ApiOperation(value = "获取消息数据")
    @Override
    public JsonVO<DocumentDTO> queryFormData(String xid) {

        return JsonVO.success(cmsFormService.getDocumentFormData(xid));
    }
}

