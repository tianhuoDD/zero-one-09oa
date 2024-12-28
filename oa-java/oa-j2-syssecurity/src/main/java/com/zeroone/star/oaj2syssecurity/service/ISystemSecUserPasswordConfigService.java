package com.zeroone.star.oaj2syssecurity.service;

import com.zeroone.star.project.dto.j2.system.security.password.UserPasswordConfigDTO;
import com.zeroone.star.project.vo.j2.system.security.password.UserPasswordConfigVO;

/**
 * 用户密码配置业务层
 * @author JIAN
 */
public interface ISystemSecUserPasswordConfigService {
    /**
     * 获取所有用户密码密码配置(不存在的配置使用默认值)
     * @return 查询结果
     */
    UserPasswordConfigVO getAllConfigOrDefault();

    /**
     * 更新/创建非空的用户密码配置
     * @param userPasswordConfigDTO 用户密码配置信息
     */
    void saveOrUpdateConfig(UserPasswordConfigDTO userPasswordConfigDTO);
}