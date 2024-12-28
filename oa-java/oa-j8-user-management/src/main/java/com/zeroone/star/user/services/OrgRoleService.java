package com.zeroone.star.user.services;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j8.user.role_position.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.role_position.RoleVO;
import com.zeroone.star.user.entity.OrgRole;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_role】的数据库操作Service
 * @createDate 2024-10-24 20:49:30
 */
public interface OrgRoleService extends IService<OrgRole> {

    JsonVO<PageDTO<RoleVO>> getList(RoleQuery query);
}
