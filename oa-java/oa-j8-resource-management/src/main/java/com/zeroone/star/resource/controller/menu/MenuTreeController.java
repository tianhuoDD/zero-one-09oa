package com.zeroone.star.resource.controller.menu;

import com.zeroone.star.project.dto.j8.resource.menu.MenuDTO;
import com.zeroone.star.project.j8.resource.menu.MenuTreeApis;
import com.zeroone.star.project.query.j8.resource.menu_permission.MenuPermissionsQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.resource.services.OrgMenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import java.util.List;
import javax.annotation.Resource;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 描述：菜单树业务控制器
 * </p>
 *
 * @author 门门
 * @version 1.0.0
 */
@RestController
@RequestMapping("/org/menu")
@Api(tags = "获取菜单树")
@Validated
@Slf4j
public class MenuTreeController implements MenuTreeApis {

    @Resource
    private OrgMenuService orgMenuService;

    @GetMapping("/tree")
    @ApiOperation(value = "获取菜单树")
    public JsonVO<List<MenuDTO>> getMenuTree(@RequestBody MenuPermissionsQuery condition) {
        log.info("获取菜单树:{}",condition);
        List<MenuDTO> menuTree = orgMenuService.getMenuTree(condition);
        return JsonVO.success(menuTree);
    }

}
