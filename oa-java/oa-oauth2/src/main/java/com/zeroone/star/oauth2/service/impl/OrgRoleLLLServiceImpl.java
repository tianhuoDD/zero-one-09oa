package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.entity.OrgRole;
import com.zeroone.star.oauth2.mapper.OrgMenuLLLMapper;
import com.zeroone.star.oauth2.mapper.OrgRoleLLLMapper;
import com.zeroone.star.oauth2.service.OrgRoleLLLService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.Collections;
import java.util.List;

@Service
public class OrgRoleLLLServiceImpl extends ServiceImpl<OrgRoleLLLMapper, OrgRole> implements OrgRoleLLLService {

    @Resource
    private OrgRoleLLLMapper orgRoleLLLMapper;

    @Resource
    OrgMenuLLLMapper orgMenuLLLMapper;

    /**
     * 根据菜单路径获取角色列表
     *
     * @param linkUrl 菜单路径
     *                orgRoleIds 角色id列表
     * @return 角色列表
     */
    @Override
    public List<OrgRole> listRoleByMenuPath(String linkUrl) {
        if (linkUrl == null) {
            return Collections.emptyList();
        }

        //根据对应的菜单查询org_role_menuList表中的的角色id
        List<String> orgRoleIds = orgMenuLLLMapper.listRoleIdByMenuList(linkUrl);
        if (orgRoleIds == null || orgRoleIds.isEmpty()) {
            return Collections.emptyList();
        }
        //根据角色id查询角色信息
        List<OrgRole> orgRoleList = orgRoleLLLMapper.listRoleById(orgRoleIds);
        if (orgRoleList == null || orgRoleList.isEmpty()) {
            return Collections.emptyList();
        }
        return orgRoleList;
    }

    /**
     * 根据用户xid获取角色列表
     *
     * @param personXid
     * @return
     */
    @Override
    public List<OrgRole> listRoleByUserId(String personXid) {
        if (personXid == null) {
            return Collections.emptyList();
        }
        List<OrgRole> orgRoleList = orgRoleLLLMapper.listRoleByUserId(personXid);
        return orgRoleList;

    }
}
