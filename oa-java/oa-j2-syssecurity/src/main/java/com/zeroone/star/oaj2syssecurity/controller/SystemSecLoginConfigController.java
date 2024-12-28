package com.zeroone.star.oaj2syssecurity.controller;


import com.zeroone.star.oaj2syssecurity.service.SystemSecLoginConfigService;
import com.zeroone.star.project.dto.j2.system.security.login.LoginSaveDTO;
import com.zeroone.star.project.j2.system.security.login.LoginConfigApis;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.security.login.LoginConfigVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("syssecurity/login-config")
@Api(tags = "登录配置")
public class SystemSecLoginConfigController implements LoginConfigApis {

    @Resource
    private SystemSecLoginConfigService systemSecLoginConfigService;

    @ApiOperation("获取登录配置")
    @GetMapping("query-loginConfig")
    @Override
    public JsonVO<LoginConfigVO> queryLoginConfig() {
        List<LoginConfigVO> loginConfigVOList = systemSecLoginConfigService.queryLoginConfig();

        if (loginConfigVOList != null && !loginConfigVOList.isEmpty()) {
            System.out.println("成功获取到登录配置：" + loginConfigVOList.get(0));
            return JsonVO.success(loginConfigVOList.get(0));
        } else {
            System.out.println("返回数据为空，未找到登录配置");
            return JsonVO.fail(null);
        }
    }

    /**
     *
     * @param loginSaveDTO
     * @return 是否保存成功
     */
    @ApiOperation("保存登录配置")
    @PostMapping("save-loginConfig")
    @Override
    public JsonVO<Boolean> saveLoginConfig(LoginSaveDTO loginSaveDTO) {

        boolean result = systemSecLoginConfigService.saveLoginConfig(loginSaveDTO);
        return result ? JsonVO.success(true) : JsonVO.fail(false);
    }
}
