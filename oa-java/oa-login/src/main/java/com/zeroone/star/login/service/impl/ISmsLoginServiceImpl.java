package com.zeroone.star.login.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.anji.captcha.service.CaptchaService;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.cloud.oauth2.entity.Oauth2Token;
import com.zeroone.star.login.mapper.OrgPersonForgotMapper;
import com.zeroone.star.login.service.ISmsLoginService;
import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.project.components.sms.aliyun.SmsComponent;
import com.zeroone.star.project.components.sms.aliyun.SmsResult;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j1.forgotPassword.OrgPersonDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.security.SecureRandom;
import java.util.HashMap;
import java.util.Map;

@Service
public class ISmsLoginServiceImpl extends ServiceImpl<OrgPersonForgotMapper, OrgPersonDTO> implements ISmsLoginService {

    @Resource
    private SmsComponent smsComponent;

    @Resource
    CaptchaService captchaService;

    @Resource
    OauthService oAuthService;

    @Resource
    UserHolder userHolder;

    @Value("${zo.cloud.starter.oauth2.mgr-id}")
    String clientId;

    @Value("${zo.cloud.starter.oauth2.mgr-password}")
    String clientPassword;

    @Resource
    RedisTemplate<String, Object> redisTemplate;

    private static final String NUMERIC_STRING = "0123456789";
    private static final SecureRandom random = new SecureRandom();

    private String generateVerificationCode(int length) {
        StringBuilder code = new StringBuilder(length);
        for (int i = 0; i < length; i++) {
            int index = random.nextInt(NUMERIC_STRING.length());
            code.append(NUMERIC_STRING.charAt(index));
        }
        return code.toString();
    }

    @Override
    public JsonVO<Oauth2TokenDTO> loginPersonByPhoneCode(String phoneCode, String phoneNum) {
        // 从 Redis 中获取存储的验证码
        String code = (String) redisTemplate.opsForValue().get(phoneNum);

        // 检查验证码是否存在
        if (code == null) {
            return JsonVO.create(null, 6110, "验证码已失效，请重新获取");
        }

        // 验证码匹配
        if (!code.equals(phoneCode)) {
            return JsonVO.create(null, 6111, "验证码不正确");
        }

        // 验证成功，执行登录逻辑
        // 生成 OAuth2 令牌
        Map<String, String> params = new HashMap<>(5);
        params.put("grant_type", "password");
        params.put("client_id", clientId);
        params.put("client_secret", clientPassword);
        params.put("username", phoneNum);
        params.put("password", phoneCode);
        Oauth2Token oauth2Token = oAuthService.postAccessToken(params);

        // 认证失败
        if (oauth2Token.getErrorMsg() != null) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), oauth2Token.getErrorMsg());
        }

        // 将登录凭证保存到 Redis
        LambdaQueryWrapper<OrgPersonDTO> wrapper = new LambdaQueryWrapper<OrgPersonDTO>()
                .eq(OrgPersonDTO::getXmobile, phoneNum);
        OrgPersonDTO person = baseMapper.selectOne(wrapper);
        redisTemplate.opsForValue().set(person.getXname(), oauth2Token);

        // 返回成功的 JSON 响应
        return JsonVO.success(BeanUtil.toBean(oauth2Token, Oauth2TokenDTO.class));
    }

    @Override
    public String getPhoneCode(String phoneNum) {
        // 1. 查询用户信息
        LambdaQueryWrapper<OrgPersonDTO> wrapper = new LambdaQueryWrapper<OrgPersonDTO>()
                .eq(OrgPersonDTO::getXmobile, phoneNum);
        OrgPersonDTO person = baseMapper.selectOne(wrapper);
        if (person == null) {
            return null;
        }
        // 2. 生成验证码
        String code = generateVerificationCode(6);
        // 3 . 发送验证码
        Map<String, String> templateParams = new HashMap<>();
        templateParams.put("code", code);
        SmsResult smsResult = smsComponent.sendSms(person.getXmobile(), "凯尔希CRM", "SMS_475010449", templateParams);
        if (!smsResult.getCode().equals("OK")) return null;
        return code;
    }
}
