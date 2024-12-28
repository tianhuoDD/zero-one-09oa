package com.zeroone.star.bizcenter.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.PpCReadcompleted;
import com.zeroone.star.bizcenter.mapper.PpCReadcompletedMapper;
import com.zeroone.star.bizcenter.service.IPpCReadcompletedService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCReadcompletedDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCReadcompletedQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

//类型转换，do转dto
@Mapper(componentModel = "spring")
interface ReadcompletedTranstfer{
    /**
     * 待办do转dto
     * @param ppCReadcompleted
     * @return
     */
    public PpCReadcompletedDTO do2dto(PpCReadcompleted ppCReadcompleted);
}
/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-29
 */
@Service
public class PpCReadcompletedServiceImpl extends ServiceImpl<PpCReadcompletedMapper, PpCReadcompleted> implements IPpCReadcompletedService {
    //notation for mapstruct
    @Resource
    private ReadcompletedTranstfer readcompletedTranstfer;
    @Override
    public PageDTO<PpCReadcompletedDTO> selectReadcompletedByPerson(PpCReadcompletedQuery query) {
        //1.构建分页模型
        Page<PpCReadcompleted> page = new Page<>(query.getPageIndex(), query.getPageSize());

        //2.构建查询条件
        QueryWrapper<PpCReadcompleted> queryWrapper = new QueryWrapper<>();

        // person必需，加入查询条件
        queryWrapper.eq("xperson", query.getPerson());

        // title可以为空，判断后再加入查询条件
        if (StringUtils.isNotBlank(query.getKeyValue())) {
            queryWrapper.like("xtitle", query.getKeyValue());
        }

        //3.执行查询
        Page<PpCReadcompleted> result =  baseMapper.selectPage(page, queryWrapper);

        //DO转DTO
        return PageDTO.create(page,readcompletedTranstfer::do2dto);
    }

}
