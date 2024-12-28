package com.zeroone.star.project.j1.person;

import com.zeroone.star.project.dto.j1.person.setting.MotifyMailhanDTO;
import com.zeroone.star.project.dto.j1.person.setting.MotifyPhonehanDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.person.setting.MotifyMailhanVO;
import com.zeroone.star.project.vo.j1.person.setting.MotifyPhonehanVO;
import com.zeroone.star.project.vo.j1.person.setting.PersonInfohanVO;

/**
 * 更改手机号和邮箱
 */
public interface MotifyPMApishan {
    /**
     * 更改手机号
     * @param motifyPhonehanDTO
     * @return
     */
    JsonVO<MotifyPhonehanVO> MotifyPhone(MotifyPhonehanDTO motifyPhonehanDTO);

    /**
     * 更改手机号
     * @param motifyMailhanDTO
     * @return
     */
    JsonVO<MotifyMailhanVO> MotifyMail(MotifyMailhanDTO motifyMailhanDTO);
}
