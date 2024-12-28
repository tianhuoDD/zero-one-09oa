package com.zeroone.star.settings.controller;

import com.zeroone.star.project.components.mail.MailComponent;
import com.zeroone.star.project.components.mail.MailMessage;
import com.zeroone.star.project.components.sms.aliyun.SmsComponent;
import com.zeroone.star.project.dto.j1.person.setting.MotifyMailhanDTO;
import com.zeroone.star.project.dto.j1.yanzhengma.mail.MailyzInfoDTO;
import com.zeroone.star.project.dto.mail.MailDTO;
import com.zeroone.star.project.j1.yanzhengma.MailyzApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.yanzhengma.mail.MailyzInfoVO;
import com.zeroone.star.project.vo.login.MailVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.BeanUtils;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.HashMap;
import java.util.concurrent.TimeUnit;

@RestController
@RequestMapping("settings/yanzhengma-mail")
@Api(tags = "个人设置")
public class YanzhengmaMailController implements MailyzApis {

    @Resource
    private MailComponent mailComponent;

    @Resource
    RedisTemplate redisTemplate;

    @Override
    @PostMapping("mail-info")
    @ApiOperation("获取邮箱验证码")
    public JsonVO<MailVO> modifyPersonInfo(MailyzInfoDTO mailyzInfoDTO) {
        MailVO mailMessage = new MailVO();
//        String yzm = "123456";
//        redisTemplate.opsForValue().set(mailyzInfoDTO.getMail(), yzm, 3, TimeUnit.MINUTES);
//        String addressFrom = "18737641711@163.com";
//        mailMessage.setFrom(addressFrom);
//        mailMessage.setFrom("han");
//        mailMessage.setTo(mailyzInfoDTO.getMail());
//        mailMessage.setSubject("test");
//        mailMessage.setText(yzm);
//        MailMessage result = mailComponent.sendMail(mailMessage);
//        if ("OK".equalsIgnoreCase(result.getStatus())) {
//            return JsonVO.success(null);
//        }
        return JsonVO.fail(null);
    }
}
