package com.zeroone.star.oauth2.service.impl.oauth2;

import com.zeroone.star.oauth2.entity.OrgMenu;
import com.zeroone.star.oauth2.entity.OrgRole;
import com.zeroone.star.oauth2.service.OrgMenuLLLService;
import com.zeroone.star.oauth2.service.OrgRoleLLLService;
import com.zeroone.star.project.constant.RedisConstant;

import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

/**
 * <p>
 * 描述：资源与角色缓存初始化服务
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class ResourcesServiceImpl {
    @Resource
    private RedisTemplate<String, Object> redisTemplate;
    @Resource
    private OrgMenuLLLService menuService;
    @Resource
    private OrgRoleLLLService orgRoleLLLService;

    /**
     * 加载资源与角色缓存
     *
     * @param isClearCacheBeforeLoad 加载前是否清除缓存
     */
    @Transactional
    public void loadData(boolean isClearCacheBeforeLoad) {
        // 清除缓存
        if (isClearCacheBeforeLoad) {
            redisTemplate.delete(RedisConstant.RESOURCE_ROLES_MAP);
        }

        // 定义缓存map
        Map<String, List<String>> resourceRolesMap = new TreeMap<>();

        // 1 获取所有菜单
        List<OrgMenu> tOrgMenus = menuService.listAllLinkUrl();
            tOrgMenus.forEach(orgMenu -> {

                // 2 获取菜单对应的角色
                String linkUrl = orgMenu.getLinkUrl();
                if (linkUrl != null && !linkUrl.isEmpty()) {
                    List<OrgRole> rolesMenu = orgRoleLLLService.listRoleByMenuPath(linkUrl);
                    if (rolesMenu != null && !rolesMenu.isEmpty()) {
                        List<String> roles = new ArrayList<>();
                        rolesMenu.forEach(role -> roles.add(role.getXunique()));
                        resourceRolesMap.put(linkUrl, roles);
                    }
                }
            });


        // 将资源缓存到redis
        redisTemplate.opsForHash().putAll(RedisConstant.RESOURCE_ROLES_MAP, resourceRolesMap);
    }

    @PostConstruct
    public void init() {
        loadData(false);
    }
}
