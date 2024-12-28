package com.zeroone.star.resource.controller.menu;

import com.zeroone.star.project.dto.j8.resource.menu.MenuDTO;
import com.zeroone.star.project.j8.resource.menu.MenuApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.resource.services.OrgMenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import javax.annotation.Resource;
import javax.validation.Valid;
import javax.validation.constraints.NotBlank;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 描述：菜单业务控制器
 * </p>
 *
 * @author DOT
 * @version 1.0.0
 */
@RestController
@RequestMapping("/org/menu")
@Api(tags = "菜单管理")
@Validated
@Slf4j
public class MenuController implements MenuApis {

    @Resource
    private OrgMenuService orgMenuService;

    @Override
    @PostMapping("/add-menu")
    @ApiOperation(value = "新增菜单项")
    public JsonVO<String> addMenu(@Valid @RequestBody MenuDTO menuDTO) {
        log.info("新增菜单项：{}", menuDTO);
        // 直接调用服务层方法添加菜单
        return orgMenuService.addMenu(menuDTO);
    }

    @Override
    @GetMapping("/query-by-id")
    @ApiOperation(value = "根据 ID 查询菜单")
    public JsonVO<MenuDTO> queryMenuByID(@NotBlank @RequestParam String menuID) {
        log.info("根据 ID {} 查询菜单", menuID);
        // 调用服务层方法根据ID查询菜单
        return orgMenuService.queryMenuByID(menuID);
    }

    @Override
    @PutMapping("/modify-menu")
    @ApiOperation(value = "修改指定菜单")
    public JsonVO<String> modifyMenu(@Valid @RequestBody MenuDTO menuDTO) {
        // 检查菜单ID是否为空
        if (menuDTO.getMenuId() == null || menuDTO.getMenuId().isEmpty()) {
            return JsonVO.create("", ResultStatus.PARAMS_INVALID);
        }
        log.info("修改菜单：{}", menuDTO);
        // 调用服务层方法修改菜单
        return orgMenuService.modifyMenu(menuDTO);
    }

    @Override
    @DeleteMapping("/remove-menu")
    @ApiOperation(value = "删除指定菜单")
    public JsonVO<String> removeMenu(@Valid @RequestBody MenuDTO menuDTO) {
        // 检查菜单ID是否为空
        if (menuDTO.getMenuId() == null || menuDTO.getMenuId().isEmpty()) {
            return JsonVO.create("", ResultStatus.PARAMS_INVALID);
        }
        log.info("删除菜单：{}", menuDTO);
        // 调用服务层方法删除菜单
        return orgMenuService.removeMenu(menuDTO);
    }
}
