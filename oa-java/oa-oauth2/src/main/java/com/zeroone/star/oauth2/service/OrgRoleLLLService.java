package com.zeroone.star.oauth2.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oauth2.entity.OrgRole;


import java.util.List;

/**
 * @author LLL
 * 操作org_role表
 */
public interface OrgRoleLLLService extends IService<OrgRole> {


    /**
     * 根据菜单MenuId查询角色
     * @param MenuId
     * @return
     */
    List<OrgRole> listRoleByMenuPath(String MenuId);

    /**
     * 根据用户id查询角色
     * @param personXid
     * @return
     */
    List<OrgRole> listRoleByUserId(String personXid);
}
