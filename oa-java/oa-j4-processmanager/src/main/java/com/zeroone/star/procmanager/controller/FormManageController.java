package com.zeroone.star.procmanager.controller;


import com.zeroone.star.procmanager.service.IFormManageService;
import com.zeroone.star.project.dto.j4.form.manage.UpdateFormDTO;
import com.zeroone.star.project.j4.form.FormManageApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.form.manage.UpdateFormVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

@RestController
@RequestMapping("/form")
@Api(tags = "表单操作")
public class FormManageController implements FormManageApis {

    @Resource
    IFormManageService formManageService;

/*    @Override
    @ApiOperation("获取表单内容")
    @GetMapping("/form-get")
    public JsonVO<UpdateFormVO> getForm(String xid) {
        return null;
    }*/

    @Override
    @ApiOperation("新增表单")
    @PostMapping("/form-add")
    public JsonVO<Boolean> addForm(UpdateFormDTO updateFormDTO) {

        Boolean result = formManageService.addForm(updateFormDTO);
        if(result){
            return new JsonVO<>(200,"新增成功",null);
        }
        return new JsonVO<>(200,"新增失败",null);
    }

    @Override
    @ApiOperation("获取表单内容更新")
    @PostMapping("/form-update")
    public JsonVO<Boolean> updateForm(UpdateFormDTO updateFormDTO) {
        Boolean result = formManageService.updateForm(updateFormDTO);
        if(result){
            return new JsonVO<>(200,"修改成功",null);
        }
        return new JsonVO<>(200,"修改失败",null);
    }
    /**
     * @description:删除表单controller
     * @author: quhutunlang
     * @date: 2024/10/26 12:51
     * @param: [xids]可能一下删除多个表单，传入表单的xid数组
     * @return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     **/
    @Override
    @ApiOperation("删除表单")
    @DeleteMapping("/form-delete")
    public JsonVO<Boolean> deleteForm(String[] xids) {

        Boolean result = formManageService.deleteForm(xids);
        if(result){
            return new JsonVO<>(200,"删除成功",null);
        }
        return new JsonVO<>(200,"删除失败",null);
    }

}
