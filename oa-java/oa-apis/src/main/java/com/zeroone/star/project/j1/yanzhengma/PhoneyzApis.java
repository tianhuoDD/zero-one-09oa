package com.zeroone.star.project.j1.yanzhengma;

import com.zeroone.star.project.dto.j1.yanzhengma.phone.PhoneyzInfoDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.yanzhengma.Phone.PhoneyzInfoVO;

/**
 * 短信验证码接口声明
 */
public interface PhoneyzApis {
    /**
     *短信验证码
     * @param phoneyzInfoDTO
     * @return PhoneyzInfoVO
     */
    JsonVO<PhoneyzInfoVO> modifyPersonInfo(PhoneyzInfoDTO phoneyzInfoDTO);
}
