package com.zeroone.star.settings.controller;

import com.zeroone.star.project.components.sms.aliyun.SmsComponent;
import com.zeroone.star.project.components.sms.aliyun.SmsResult;
import com.zeroone.star.project.config.redis.RedisConfig;
import com.zeroone.star.project.dto.j1.yanzhengma.phone.PhoneyzInfoDTO;
import com.zeroone.star.project.j1.yanzhengma.PhoneyzApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.yanzhengma.Phone.PhoneyzInfoVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.apache.ibatis.jdbc.Null;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.HashMap;
import java.util.concurrent.TimeUnit;


@RequestMapping("settings/yanzhengma-phone")
@RestController
@Api(tags = "个人设置")
public class YanzhengmaPhoneController implements PhoneyzApis {

    @Resource
    SmsComponent sms;

    @Resource
    RedisTemplate redisTemplate;

    @Override
    @PutMapping("phone-info")
    @ApiOperation("获取短信验证码")
    public JsonVO<PhoneyzInfoVO> modifyPersonInfo(PhoneyzInfoDTO phoneyzInfoDTO) {

        String phone = phoneyzInfoDTO.getPhone();
        HashMap<String, String> map = new HashMap<>(1);
        String yzm = "12345";
        redisTemplate.opsForValue().set(phone, yzm, 3, TimeUnit.MINUTES);
        map.put("code", yzm);
        PhoneyzInfoVO vo = new PhoneyzInfoVO();
        vo.setYanzhengma(yzm);
        SmsResult smsResult = sms.sendSms(phone, "阿里云短信测试", "SMS_154950909", map);
        if ("OK".equals(smsResult.getCode())) {
            return JsonVO.success(vo);
        }
        return JsonVO.fail(vo);
    }
}
