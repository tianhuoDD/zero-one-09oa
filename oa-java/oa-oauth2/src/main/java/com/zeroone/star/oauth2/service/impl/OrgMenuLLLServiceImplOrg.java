package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;


import com.zeroone.star.oauth2.entity.OrgMenu;
import com.zeroone.star.oauth2.mapper.OrgMenuLLLMapper;
import com.zeroone.star.oauth2.service.OrgMenuLLLService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 菜单 服务实现类
 * </p>
 *
 * @author 阿伟
 */
@Service
public class OrgMenuLLLServiceImplOrg extends ServiceImpl<OrgMenuLLLMapper, OrgMenu> implements OrgMenuLLLService {

    @Override
    public List<OrgMenu> listAllLinkUrl() {

        QueryWrapper<OrgMenu> wrapper = new QueryWrapper<>();
        wrapper.select("link_url");
        wrapper.eq(" menu_type", 1);

        List<OrgMenu> orgMenus = baseMapper.selectList(wrapper);
        return orgMenus;
    }


}
