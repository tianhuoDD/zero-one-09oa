package com.zeroone.star.project.j8.user;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.role_position.AddUserPositionDTO;
import com.zeroone.star.project.query.j8.user.role_position.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.role_position.RoleVO;
import com.zeroone.star.project.vo.j8.user.role_position.UnitDutyVO;
import com.zeroone.star.project.vo.j8.user.role_position.UnitVO;
import java.util.List;

public interface RolePositionApis {

    /**
     * 为设置个人身份（分配职务）
     */
    JsonVO<String> addUserPosition(AddUserPositionDTO addUserPositionDTO);

    /**
     * 根据用户ID查询顶级组织列表
     */
    JsonVO<List<UnitVO>> getTopUnitList(String userId);

    /**
     * 根据组织ID查询子组织列表
     */
    JsonVO<List<UnitVO>> getChildrenUnitList(String unitId);

    /**
     * 根据组织ID查找拥有的职务
     */
    JsonVO<List<UnitDutyVO>> getUnitDutyList(String unitId);

    /**
     * 获取角色列表（分页）
     */
    JsonVO<PageDTO<RoleVO>> getRoleList(RoleQuery query);
}
