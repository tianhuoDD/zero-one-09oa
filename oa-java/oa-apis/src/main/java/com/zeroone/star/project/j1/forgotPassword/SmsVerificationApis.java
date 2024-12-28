package com.zeroone.star.project.j1.forgotPassword;

import com.zeroone.star.project.dto.j1.forgotPassword.SmsVerificationDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * SMS验证API接口
 * 该接口用于通过手机短信进行用户验证，提供SMS验证的方法
 */
public interface SmsVerificationApis {
    /**
     * 忘记密码服务接口
     *
     * @param xmobile 验证码 DTO，包含验证码信息
     * @return 返回一个 JsonVO 对象，表示操作结果
     * @author kaltsit
     */
    JsonVO<SmsVerificationDTO> querySmsVerification(String xmobile);
}