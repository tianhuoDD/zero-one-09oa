package com.zeroone.star.project.j1.person;

import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.vo.JsonVO;
import springfox.documentation.spring.web.json.Json;

/**
 * 用户手机号登录接口
 */
public interface PersonLoginByPhoneCodeApis {


    /**
     * 用户手机号登录
     * @param phoneCode 手机验证码
     * @param phoneNum 手机号
     * @return 返回登录结果
     */
    JsonVO<Oauth2TokenDTO> loginPersonByPhoneCode(String phoneCode, String phoneNum);

    /**
     * 用户获取手机验证码
     * @param phoneNum 用户手机号
     * @return 返回获取到的手机验证码
     */
    JsonVO<String> getPhoneCode(String phoneNum);

}
