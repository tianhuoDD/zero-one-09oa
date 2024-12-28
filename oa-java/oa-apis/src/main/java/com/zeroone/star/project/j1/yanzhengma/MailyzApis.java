package com.zeroone.star.project.j1.yanzhengma;

import com.zeroone.star.project.dto.j1.person.setting.MotifyMailhanDTO;
import com.zeroone.star.project.dto.j1.yanzhengma.mail.MailyzInfoDTO;
import com.zeroone.star.project.dto.mail.MailDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.yanzhengma.mail.MailyzInfoVO;
import com.zeroone.star.project.vo.login.MailVO;

/**
 * 邮箱验证码接口声明
 */
public interface MailyzApis {
    /**
     * 邮箱验证码
     * @param mailyzInfoDTO
     * @return MailyzInfoVO
     */
    JsonVO<MailVO> modifyPersonInfo(MailyzInfoDTO mailyzInfoDTO);
}
