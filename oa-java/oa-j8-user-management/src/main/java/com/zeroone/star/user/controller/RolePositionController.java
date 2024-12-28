package com.zeroone.star.user.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.user.role_position.AddUserPositionDTO;
import com.zeroone.star.project.j8.user.RolePositionApis;
import com.zeroone.star.project.query.j8.user.role_position.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.role_position.RoleVO;
import com.zeroone.star.project.vo.j8.user.role_position.UnitDutyVO;
import com.zeroone.star.project.vo.j8.user.role_position.UnitVO;
import com.zeroone.star.user.services.OrgPersonTopunitlistService;
import com.zeroone.star.user.services.OrgRoleService;
import com.zeroone.star.user.services.OrgUnitService;
import com.zeroone.star.user.services.OrgUnitdutyService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import java.util.List;
import javax.annotation.Resource;
import lombok.RequiredArgsConstructor;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Api(tags = "职务和角色")
@RestController
@RequestMapping("/org/user/role")
@Validated
@RequiredArgsConstructor
public class RolePositionController implements RolePositionApis {

    @Resource
    OrgUnitdutyService orgUnitdutyService;

    @Resource
    OrgPersonTopunitlistService orgPersonTopunitlistService;

    @Resource
    OrgUnitService orgUnitService;

    @Resource
    OrgRoleService orgRoleService;

    /**
     * 为设置个人身份（分配职务）
     */
    @ApiOperation("为设置个人身份（分配职务）")
    @PostMapping(value = "/add-position")
    public JsonVO<String> addUserPosition(@Validated @RequestBody AddUserPositionDTO addUserPositionDTO) {

        return orgUnitdutyService.addUserPosition(addUserPositionDTO);
    }

    /**
     * 根据用户ID查询顶级组织列表
     */
    @ApiOperation("根据用户ID查询顶级组织列表")
    @GetMapping(value = "/top/{userId}")
    public JsonVO<List<UnitVO>> getTopUnitList(@PathVariable String userId) {
        return orgPersonTopunitlistService.selectTopUnitListByUserId(userId);
    }

    /**
     * 根据组织ID查询子组织列表
     */
    @ApiOperation("根据组织ID查询子组织列表")

    @GetMapping(value = "/children/unit/{unitId}")
    public JsonVO<List<UnitVO>> getChildrenUnitList(@PathVariable String unitId) {

        return orgUnitService.getChildrenUnitList(unitId);
    }

    /**
     * 根据组织ID查找拥有的职务
     */

    @ApiOperation("根据组织ID查找拥有的职务")
    @GetMapping(value = "/children/duty/{unitId}")
    public JsonVO<List<UnitDutyVO>> getUnitDutyList(@PathVariable String unitId) {
        return orgUnitdutyService.getUnitDutyList(unitId);
    }

    /**
     * 获取角色列表
     */

    @ApiOperation("获取角色列表")
    @GetMapping(value = "/role/list")
    public JsonVO<PageDTO<RoleVO>> getRoleList(@RequestBody RoleQuery query) {

        return orgRoleService.getList(query);
    }


}
