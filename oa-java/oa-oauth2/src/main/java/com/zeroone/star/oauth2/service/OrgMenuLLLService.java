package com.zeroone.star.oauth2.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oauth2.entity.OrgMenu;

import java.util.List;

/**
 * <p>
 * 菜单 服务类
 * </p>
 *
 * @author 阿伟
 */
public interface OrgMenuLLLService extends IService<OrgMenu> {
    /**
     * 获取菜单中的链接地址
     * @return 查询结果
     */
    List<OrgMenu> listAllLinkUrl();
}
