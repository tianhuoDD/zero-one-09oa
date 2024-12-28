package com.zeroone.star.bizcenter.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.PpCRead;
import com.zeroone.star.bizcenter.mapper.PpCReadMapper;
import com.zeroone.star.bizcenter.service.IPpCReadService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCReadDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCReadQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

//类型转换，do转dto
@Mapper(componentModel = "spring")
interface ReadTransfer {
    /**
     * 待办do转dto
     * @param ppCRead
     * @return
     */
    public PpCReadDTO do2dto(PpCRead ppCRead);
}
/**
 * <p>
 *  服务实现类,待办查询实现
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */
@Service
public class PpCReadServiceImpl extends ServiceImpl<PpCReadMapper, PpCRead> implements IPpCReadService {

    @Resource
    private ReadTransfer readTransfer;
    @Override
    public PageDTO<PpCReadDTO> selectReadByPerson(PpCReadQuery query) {

        //1. 构建分页对象
        Page<PpCRead> page = new Page<>(query.getPageIndex(), query.getPageSize());

        //2.构建查询条件
        QueryWrapper<PpCRead> queryWrapper = new QueryWrapper<>();

        // person必需，加入查询条件
        queryWrapper.eq("xperson", query.getPerson());

        // title可以为空，判断后再加入查询条件
        if (StringUtils.isNotBlank(query.getKeyValue())) {
            queryWrapper.like("xtitle", query.getKeyValue());
        }

        //3.执行查询
        Page<PpCRead> result = baseMapper.selectPage(page, queryWrapper);
        //4.转DTO
        return PageDTO.create(result, readTransfer::do2dto);
    }
}
