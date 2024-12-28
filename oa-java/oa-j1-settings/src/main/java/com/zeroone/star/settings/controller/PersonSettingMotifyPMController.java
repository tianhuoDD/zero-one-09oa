package com.zeroone.star.settings.controller;

import com.zeroone.star.project.dto.j1.person.setting.MotifyMailhanDTO;
import com.zeroone.star.project.dto.j1.person.setting.MotifyPhonehanDTO;
import com.zeroone.star.project.j1.person.MotifyPMApishan;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.person.setting.MotifyMailhanVO;
import com.zeroone.star.project.vo.j1.person.setting.MotifyPhonehanVO;
import com.zeroone.star.settings.service.impl.PersonSettingMotifyMailHanServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.concurrent.TimeUnit;


@RestController
@RequestMapping("settings/motifyph")
@Api(tags = "个人设置")
public class PersonSettingMotifyPMController implements MotifyPMApishan {

    @Resource
    private PersonSettingMotifyMailHanServiceImpl personSettingMotifyMailHanService;

    @Resource
    RedisTemplate redisTemplate;

    @Override
    @PutMapping("motify-phone")
    @ApiOperation("更换手机")
    public JsonVO<MotifyPhonehanVO> MotifyPhone(MotifyPhonehanDTO motifyPhonehanDTO) {
        String tojy = personSettingMotifyMailHanService.MotifyPhoneNumber(motifyPhonehanDTO);
        MotifyPhonehanVO motifyPhonehanVO = new MotifyPhonehanVO();
        motifyPhonehanVO.setTojy(tojy);

        if (tojy.equalsIgnoreCase("1")) {
            return JsonVO.success(motifyPhonehanVO);
        }
        else {
            return JsonVO.fail(motifyPhonehanVO);
        }
    }

    @Override
    @PutMapping("motify-mail")
    @ApiOperation("更换邮箱")
    public JsonVO<MotifyMailhanVO> MotifyMail(MotifyMailhanDTO motifyMailhanDTO) {
        String tojy = personSettingMotifyMailHanService.MotifyMailNumber(motifyMailhanDTO);
        MotifyMailhanVO motifyMailhanVO = new MotifyMailhanVO();
        motifyMailhanVO.setTojy(tojy);
        if (tojy.equalsIgnoreCase("1")) {
            return JsonVO.success(motifyMailhanVO);
        }
        else {
            return JsonVO.fail(motifyMailhanVO);
        }
    }
}
