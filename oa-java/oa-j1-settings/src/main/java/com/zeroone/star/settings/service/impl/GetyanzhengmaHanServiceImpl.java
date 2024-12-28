package com.zeroone.star.settings.service.impl;

import com.zeroone.star.settings.service.IgetYanzhengmaHanService;
import org.springframework.stereotype.Service;

@Service
public class GetyanzhengmaHanServiceImpl implements IgetYanzhengmaHanService {

    /**
     * 获取短信验证码
     * @param phone
     * @return 验证码
     */
    @Override
    public String getPhoneYzm(String phone) {

        return "";
    }

    /**
     * 获取邮箱验证码
     * @param mail
     * @return 验证码
     */
    @Override
    public String grtMailYzm(String mail) {
        return "";
    }
}
