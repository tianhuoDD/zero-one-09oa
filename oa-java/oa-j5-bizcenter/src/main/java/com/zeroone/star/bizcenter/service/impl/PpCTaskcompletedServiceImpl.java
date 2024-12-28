package com.zeroone.star.bizcenter.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.PpCTaskcompleted;
import com.zeroone.star.bizcenter.mapper.PpCTaskcompletedMapper;
import com.zeroone.star.bizcenter.service.IPpCTaskcompletedService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCTaskcompletedDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCTaskcompletedQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类,查询参阅记录
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */

@Mapper(componentModel = "spring")
interface TaskCompleteTransfer{
    /**
     * @Description:  类型转换器，用于DO转DTO
     * @Param: PpCTask
     * @return:  PpCTaskDTO
     * @Author: hamhuo
     * @Date:
     */
    PpCTaskcompletedDTO taskcompleted2Dto(PpCTaskcompleted ppCTaskComplete);
}

/**
 * <p>
 *  服务实现类,已办查询
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-29
 */
@Service
public class PpCTaskcompletedServiceImpl extends ServiceImpl<PpCTaskcompletedMapper, PpCTaskcompleted> implements IPpCTaskcompletedService {

    @Resource
    private TaskCompleteTransfer taskCompleteTransfer;

    @Override
    public PageDTO<PpCTaskcompletedDTO> selectTaskCompleteByPerson(PpCTaskcompletedQuery query) {


        //创建分页模型
        Page<PpCTaskcompleted> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构造查询条件
        QueryWrapper<PpCTaskcompleted> queryWrapper = new QueryWrapper<>();

        // person必需，加入查询条件
        queryWrapper.eq("xperson", query.getPerson());

        // title可以为空，判断后再加入查询条件
        if (StringUtils.isNotBlank(query.getKeyValue())) {
            queryWrapper.like("xtitle", query.getKeyValue());
        }

        //执行查询
        Page<PpCTaskcompleted> result = baseMapper.selectPage(page, queryWrapper);
        return PageDTO.create(result,   taskCompleteTransfer::taskcompleted2Dto);
    }
}
