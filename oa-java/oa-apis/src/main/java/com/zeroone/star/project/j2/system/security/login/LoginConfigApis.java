package com.zeroone.star.project.j2.system.security.login;


import com.zeroone.star.project.dto.j2.system.security.login.LoginSaveDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.security.login.LoginConfigVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;

@Api(tags = "登录配置")
public interface LoginConfigApis {

    @ApiOperation("获取登录配置")
    JsonVO<LoginConfigVO> queryLoginConfig();

    @ApiOperation("保存登录配置")
    JsonVO<Boolean> saveLoginConfig(LoginSaveDTO loginSaveDTO);
}
