package com.zeroone.star.oaj2syssecurity.controller;

import com.zeroone.star.oaj2syssecurity.service.ISystemSecUserPasswordConfigService;
import com.zeroone.star.project.dto.j2.system.security.password.UserPasswordConfigDTO;
import com.zeroone.star.project.j2.system.security.password.UserPasswordConfigApi;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.security.password.UserPasswordConfigVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * 用户密码设置前端控制器
 * @author JIAN
 */
@Slf4j
@RestController
@RequestMapping("syssecurity/user-password-config")
@Api(tags = "用户密码设置")
public class SystemSecUserPasswordConfigController implements UserPasswordConfigApi {
    @Resource
    private ISystemSecUserPasswordConfigService userPasswordConfigService;

    @Override
    @GetMapping("/query-all")
    @ApiOperation("获取配置")
    public JsonVO<UserPasswordConfigVO> queryAll() {
        return JsonVO.success(userPasswordConfigService.getAllConfigOrDefault());
    }

    @Override
    @PostMapping("/modify")
    @ApiOperation("修改配置")
    public JsonVO<Boolean> modifyConfig(@RequestBody @Validated UserPasswordConfigDTO userPasswordConfigDTO) {
        userPasswordConfigService.saveOrUpdateConfig(userPasswordConfigDTO);
        return JsonVO.success(true);
    }
}