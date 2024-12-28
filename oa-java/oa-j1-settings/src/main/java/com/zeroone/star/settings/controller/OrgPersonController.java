package com.zeroone.star.settings.controller;


import com.zeroone.star.project.dto.j1.settings.ModifyPasswordDTO;
import com.zeroone.star.project.dto.j1.settings.SaveInfoDTO;
import com.zeroone.star.project.j1.settings.SettingsApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.settings.service.IOrgPersonService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author juhao
 * @since 2024-10-21
 */
@RestController
@RequestMapping("settings/person-settings")
@Api(tags = "个人设置")
public class OrgPersonController implements SettingsApis {

    @Autowired
    IOrgPersonService orgPersonService;

    @PutMapping("password")
    @ApiOperation("修改密码")
    @Override
    public JsonVO<Boolean> ModifyPassword(@Valid ModifyPasswordDTO data) {
        Boolean bool = orgPersonService.updatePassword(data);
        if(!bool)
        {
            return JsonVO.create(false, HttpStatus.UNAUTHORIZED.value(), "密码错误");
        }
        return JsonVO.create(true, HttpStatus.OK.value(), "修改密码成功");
    }

    @PutMapping("info")
    @ApiOperation("保存个人信息")
    @Override
    public JsonVO<Boolean> SaveInfo(@RequestBody SaveInfoDTO data) {
        orgPersonService.updatePersonInfo(data);
        return JsonVO.create(true, HttpStatus.OK.value(),"保存个人信息成功");
    }
}

