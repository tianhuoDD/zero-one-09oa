package com.zeroone.star.project.j1.forgotPassword;

import com.zeroone.star.project.dto.j1.forgotPassword.NewPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.forgotPassword.NewPasswordVO;

/**
 * 新密码管理接口
 * 用于处理新密码相关的操作，例如重置密码、修改密码等
 */
public interface NewPasswordApis {
    /**
     * 重置或修改用户密码
     *
     * @param newPasswordDTO 包含新密码信息的数据传输对象
     * @return 返回一个包含操作结果信息的JsonVO对象
     */
    JsonVO<NewPasswordVO> modifyNewPassword(NewPasswordDTO newPasswordDTO);
}
