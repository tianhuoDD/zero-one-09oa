package com.zeroone.star.procmanager.controller;


import com.zeroone.star.procmanager.service.QueryFormService;
import com.zeroone.star.project.dto.j4.form.data.FormInfoDTO;
import com.zeroone.star.project.dto.j4.form.data.FormListDTO;
import com.zeroone.star.project.dto.j4.form.manage.UpdateFormDTO;
import com.zeroone.star.project.dto.j4.form.data.CategoryDTO;
import com.zeroone.star.project.j4.form.FormControllerApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.form.data.CategoryVO;
import com.zeroone.star.project.vo.j4.form.data.FormInfoVO;
import com.zeroone.star.project.vo.j4.form.data.FormListVO;
import com.zeroone.star.project.vo.j4.form.manage.UpdateFormVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/form")
@Api(tags = "表单操作")
public class FormController implements FormControllerApis
{
    @Resource
    private QueryFormService queryFormService;


/*    @Override
    @ApiOperation("获取表单内容")
    @GetMapping("/form-get")
    public JsonVO<UpdateFormVO> getForm(String xid) {
        return null;
    }*/

    @ApiOperation("获取表单详情")
    @GetMapping("/query-form-info")
     @Override
    public JsonVO<FormInfoVO> queryFormInfo(FormInfoDTO formInfoDTO)
    {
        FormInfoVO formInfoVO = queryFormService.queryFormInfo(formInfoDTO);
        if(formInfoVO == null)
        {
            return JsonVO.fail(null);
        }
        return JsonVO.success(formInfoVO);
    }

    @ApiOperation("获取表单列表")
    @GetMapping("/query-form-list")
    @Override
    public JsonVO<List<FormListVO>> queryFormList(FormListDTO formListDTO)
    {

        List<FormListVO> formListVOs = queryFormService.queryFormList(formListDTO);

        if(formListVOs == null)
        {
            return JsonVO.fail(null);
        }
        return JsonVO.success(formListVOs);
    }

    @Override
    @ApiOperation("获取所有表单类型")
    @GetMapping("/query-form-category")
    public JsonVO<List<CategoryVO>> queryCategoryVO(CategoryDTO categoryDTO)
    {
        JsonVO<List<CategoryVO>> listJsonVO = queryFormService.queryCategoryVO(categoryDTO);

        if(listJsonVO == null)
        {
            return JsonVO.fail(null);
        }

        return listJsonVO;
    }

}
