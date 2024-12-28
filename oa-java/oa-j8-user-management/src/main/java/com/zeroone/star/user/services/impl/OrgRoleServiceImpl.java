package com.zeroone.star.user.services.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j8.user.role_position.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.role_position.RoleVO;
import com.zeroone.star.user.entity.OrgRole;
import com.zeroone.star.user.mapper.OrgRoleMapper;
import com.zeroone.star.user.services.OrgRoleService;
import java.util.List;
import java.util.stream.Collectors;
import org.springframework.stereotype.Service;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_role】的数据库操作Service实现
 * @createDate 2024-10-24 20:49:30
 */
@Service
public class OrgRoleServiceImpl extends ServiceImpl<OrgRoleMapper, OrgRole>
    implements OrgRoleService {


    @Override
    public JsonVO<PageDTO<RoleVO>> getList(RoleQuery query) {
        QueryWrapper<OrgRole> queryWrapper = new QueryWrapper<>();
        queryWrapper.like(StrUtil.isNotEmpty(query.getRoleName()), "xname", query.getRoleName());
        Page<OrgRole> page = this.page(new Page<>(query.getPageIndex(), query.getPageSize()), queryWrapper);
        List<RoleVO> records = page.getRecords().stream().map(orgRole -> {
            RoleVO roleVO = new RoleVO();
            BeanUtil.copyProperties(orgRole, roleVO);
            return roleVO;
        }).collect(Collectors.toList());
        PageDTO<RoleVO> pageDTO = new PageDTO<>();
        pageDTO.setRows(records);
        pageDTO.setTotal(page.getTotal());
        return JsonVO.success(pageDTO);
    }
}




