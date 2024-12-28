package com.zeroone.star.settings.service.impl;

import com.zeroone.star.project.dto.j1.person.setting.MotifyMailhanDTO;
import com.zeroone.star.project.dto.j1.person.setting.MotifyPhonehanDTO;
import com.zeroone.star.settings.entity.OrgPerson;
import com.zeroone.star.settings.mapper.MotifyMailHan;
import com.zeroone.star.settings.mapper.MotifyPhoneHan;
import com.zeroone.star.settings.mapper.QueryMailHanMapper;
import com.zeroone.star.settings.mapper.QueryPhoneHanMapper;
import com.zeroone.star.settings.service.IPersonSettingMotifyPMHanService;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.concurrent.TimeUnit;

@Service
public class PersonSettingMotifyMailHanServiceImpl implements IPersonSettingMotifyPMHanService {
    @Resource
    private QueryPhoneHanMapper queryPhoneHanMapper;

    @Resource
    private QueryMailHanMapper queryMailHanMapper;

    @Resource
    private MotifyMailHan motifyMailHan;

    @Resource
    private MotifyPhoneHan motifyPhoneHan;

    @Resource
    RedisTemplate redisTemplate;

    @Override
    public String MotifyPhoneNumber(MotifyPhonehanDTO motifyPhonehanDTO) {
        String prePhone = motifyPhonehanDTO.getPhone();
        String id = motifyPhonehanDTO.getId();
        if (id == null || id.isEmpty()) {
            return "0";
        }
        OrgPerson orgPerson = queryPhoneHanMapper.queryPhoneHan(id);
        if (orgPerson == null) {
            return "0";
        }
        String phone = orgPerson.getXmobile();
        String pp = (String) redisTemplate.opsForValue().get(prePhone);
        if (pp == null) {
            return "0";
        }
        if (phone.equals(prePhone) && pp.equals(motifyPhonehanDTO.getVerifyCode())) {
            motifyPhoneHan.motigyPhone(motifyPhonehanDTO);
            return "1";
        }

        return "0";
    }

    @Override
    public String MotifyMailNumber(MotifyMailhanDTO motifyMailhanDTO) {
        String preMail = motifyMailhanDTO.getMail();
        String id = motifyMailhanDTO.getId();
        if (id == null || id.isEmpty()) {
            return "0";
        }
        OrgPerson orgPerson = queryMailHanMapper.queryMailHan(id);
        if (orgPerson == null) {
            return "0";
        }
        String Mail = orgPerson.getXmail();
        String code = motifyMailhanDTO.getVerifyCode();
        String mm = (String) redisTemplate.opsForValue().get(preMail);
        if (mm == null) {
            return "0";
        }
        if (Mail.equals(preMail) && code.equals(mm)) {
            motifyMailHan.motigyMail(motifyMailhanDTO);
            return "1";
        }

        return "0";
    }
}
