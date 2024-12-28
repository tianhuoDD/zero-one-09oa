package com.zeroone.star.resource.controller.menu;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.resource.menu_permission.MenuPermissionsDTO;
import com.zeroone.star.project.j8.resource.menu.MenuPermissionsApis;
import com.zeroone.star.project.query.j8.resource.menu_permission.MenuPermissionsQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.resource.services.OrgMenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import java.util.List;
import javax.annotation.Resource;
import org.springframework.stereotype.Controller;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * <p>
 * 描述：菜单功能业务控制器
 * </p>
 *
 * @author liang
 * @version 1.0.0
 */

@Api(tags = "菜单权限相关接口")
@Controller
@RequestMapping("/org/menu/permission")
public class MenuPermissionsController implements MenuPermissionsApis {
    @Resource
    OrgMenuService orgMenuService;

    @Override
    @ApiOperation("获取菜单功能的分页")
    @GetMapping(value = "/")
    public JsonVO<PageDTO<MenuPermissionsDTO>> queryMenuPermissions(@Validated MenuPermissionsQuery condition) {
        PageDTO<MenuPermissionsDTO> pageDTO = orgMenuService.queryMenuPermissions(condition).getData();
        if(pageDTO != null){
            return JsonVO.success(pageDTO);
        }
        return JsonVO.fail(null);
    }

    @Override
    @ApiOperation("多项添加菜单功能权限")
    @PostMapping(value = "/add")
    public JsonVO<Void> addMenuPermissions(@RequestBody List<MenuPermissionsDTO> MenuPermissionsDTOList) {
        if (MenuPermissionsDTOList == null || MenuPermissionsDTOList.isEmpty()) {
            return JsonVO.fail(null);
        }
        return orgMenuService.addMenuPermissions(MenuPermissionsDTOList);
    }

    @Override
    @ApiOperation("批量删除菜单功能权限")
    @DeleteMapping(value = "/delete")
    public JsonVO<Void> deleteMenuPermissions(List<Integer> MenuPermissionsIds) {
        if (MenuPermissionsIds == null || MenuPermissionsIds.isEmpty()) {
            return JsonVO.fail(null);
        }
        return orgMenuService.deleteMenuPermissions(MenuPermissionsIds);
    }

    @Override
    @ApiOperation("修改菜单功能权限")
    @PutMapping(value = "/update")
    public JsonVO<Void> modifyMenuPermissions(@RequestBody MenuPermissionsDTO MenuPermissionsDTO) {
        if (MenuPermissionsDTO == null) {
            return JsonVO.fail(null);
        }
        return orgMenuService.modifyMenuPermissions(MenuPermissionsDTO);
    }
}
