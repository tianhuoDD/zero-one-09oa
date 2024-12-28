package com.zeroone.star.project.j2.system.security.password;

import com.zeroone.star.project.dto.j2.system.security.password.UserPasswordConfigDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.security.password.UserPasswordConfigVO;

/**
 * 用户密码设置Api
 * @author JIAN
 */
public interface UserPasswordConfigApi {
    /**
     * 查询所有用户密码设置
     * @return 查询结果
     */
    JsonVO<UserPasswordConfigVO> queryAll();

    /**
     * 更新用户密码设置
     * @return true 成功 false 失败
     */
    JsonVO<Boolean> modifyConfig(UserPasswordConfigDTO userPasswordConfigDTO);
}