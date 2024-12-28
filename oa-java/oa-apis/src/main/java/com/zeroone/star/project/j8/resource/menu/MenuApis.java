package com.zeroone.star.project.j8.resource.menu;

import com.zeroone.star.project.dto.j8.resource.menu.MenuDTO;
import com.zeroone.star.project.vo.JsonVO;

import javax.validation.Valid;
import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：菜单服务接口定义
 * </p>
 * @author DOT
 * @version 1.0.0
 */
public interface MenuApis {
    /**
     * 创建新的菜单项
     * @param menuDTO 菜单数据传输对象
     * @return 创建后的菜单 ID
     */
    JsonVO<String> addMenu(@Valid MenuDTO menuDTO);

    /**
     * 根据 ID 获取菜单
     * @param menuID 菜单 ID
     * @return 查询结果
     */
    JsonVO<MenuDTO> queryMenuByID(@NotBlank String menuID);

    /**
     * 更新菜单
     * @param menuDTO 更新的菜单数据传输对象
     * @return 成功更新，返回菜单 ID
     */
    JsonVO<String> modifyMenu(@Valid MenuDTO menuDTO);

    /**
     * 逻辑删除菜单项
     * @param menuDTO 需要删除的菜单
     * @return 成功删除, 返回菜单 ID
     */
    JsonVO<String> removeMenu(@Valid MenuDTO menuDTO);
}
