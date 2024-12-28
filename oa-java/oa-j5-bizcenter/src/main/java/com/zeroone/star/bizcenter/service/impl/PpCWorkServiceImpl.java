package com.zeroone.star.bizcenter.service.impl;



import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.PpCTask;
import com.zeroone.star.bizcenter.entity.PpCWork;
import com.zeroone.star.bizcenter.mapper.PpCWorkMapper;
import com.zeroone.star.bizcenter.service.IPpCWorkService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCTaskDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCWorkDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCWorkQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
@Mapper(componentModel = "spring")
interface WorkTransfer{
    /**
     * @Description:  类型转换器，用于DO转DTO
     * @Param: PpCTask
     * @return:  PpCTaskDTO
     * @Author: hamhuo
     * @Date:
     */
    PpCWorkDTO work2taskDTO(PpCWork ppCWork);

}
/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */
@Service
public class PpCWorkServiceImpl extends ServiceImpl<PpCWorkMapper, PpCWork> implements IPpCWorkService {


    @Resource
    private WorkTransfer workTransfer;

    @Override
    public PageDTO<PpCWorkDTO> selectWorkByPerson (PpCWorkQuery query) {
        //构建分页对象,用于分页查询
        Page<PpCWork> page = new Page<>(query.getPageIndex(),query.getPageSize());

        //构建查询对象
        QueryWrapper<PpCWork> queryWrapper = new QueryWrapper<>();

        // person必需，加入查询条件
        queryWrapper.eq("xcreatorPerson", query.getPerson());

        // title可以为空，判断后再加入查询条件
        if (StringUtils.isNotBlank(query.getKeyValue())) {
            queryWrapper.like("xtitle", query.getKeyValue());
        }

        //执行查询
        Page<PpCWork> result = baseMapper.selectPage(page,queryWrapper);
        return PageDTO.create(result, workTransfer::work2taskDTO);
    }
}
