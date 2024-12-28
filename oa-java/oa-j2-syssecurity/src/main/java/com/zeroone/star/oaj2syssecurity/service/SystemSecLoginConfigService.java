package com.zeroone.star.oaj2syssecurity.service;

import com.zeroone.star.project.dto.j2.system.security.login.LoginSaveDTO;
import com.zeroone.star.project.vo.j2.system.security.login.LoginConfigVO;

import java.util.List;

/**
 * className: SystemSecLoginConfigService
 * author: maomaomao
 * date: 2024/10/28 19:10
 * Version: 1.0
 * description:
 */
public interface SystemSecLoginConfigService {

    /**
     * 保存登录配置
     * @param loginSaveDTO 登录配置参数
     * @return 登录配置是否保存成功
     */
    Boolean saveLoginConfig(LoginSaveDTO loginSaveDTO);

    /**
     * 查询登录配置
     * @return 登录配置信息
     */
    List<LoginConfigVO> queryLoginConfig();

    /**
     * 判断登录时是都需要相关验证码
     *
     * @return
     */
    int isCaptchaRequired();

    Boolean saveLoginConfigFromFile();
}
