package com.zeroone.star.oauth2.mapper;





import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oauth2.entity.OrgMenu;
import org.apache.ibatis.annotations.Mapper;


import java.util.List;

/**
 * <p>
 * 菜单 Mapper 接口
 * </p>
 *
 * @author LLL
 */

@Mapper
public interface OrgMenuLLLMapper extends BaseMapper<OrgMenu> {

    /**
     * 根据菜单路id询角色id
     * @param linkUrl 菜单路径
     * @return 角色id集合
     */
    List<String> listRoleIdByMenuList(String linkUrl);
}
