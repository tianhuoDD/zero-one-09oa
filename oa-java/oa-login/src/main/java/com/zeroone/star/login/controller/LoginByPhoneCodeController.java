package com.zeroone.star.login.controller;

import com.anji.captcha.service.CaptchaService;
import com.zeroone.star.login.service.ISmsLoginService;
import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.j1.person.PersonLoginByPhoneCodeApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * 用户手机验证码登录
 */
@RestController
@RequestMapping("login/ByPhoneCode")
@Api(tags = "用户手机验证码登录")
public class LoginByPhoneCodeController implements PersonLoginByPhoneCodeApis {

    @Resource
    RedisTemplate<String, Object> redisTemplate;

    @Resource
    CaptchaService captchaService;

    @Resource
    OauthService oAuthService;

    @Resource
    UserHolder userHolder;

    @Resource
    ISmsLoginService smsLoginService;



    @ApiOperation("用户手机验证码登录")
    @PostMapping("person-info")
    @Override
    public JsonVO<Oauth2TokenDTO> loginPersonByPhoneCode(String phoneCode, String phoneNum) {
        return smsLoginService.loginPersonByPhoneCode(phoneCode, phoneNum);
    }

    @ApiOperation("用户获取手机验证码")
    @GetMapping("person-info")
    @Override
    public JsonVO<String> getPhoneCode(String phoneNum) {
        String phoneCode = smsLoginService.getPhoneCode(phoneNum);
        if (phoneCode != null) {
            redisTemplate.opsForValue().set(phoneNum, phoneCode);
        }else {
            return JsonVO.fail("获取验证码失败");
        }
        return JsonVO.success("获取验证码成功: " + phoneCode);
    }
}
