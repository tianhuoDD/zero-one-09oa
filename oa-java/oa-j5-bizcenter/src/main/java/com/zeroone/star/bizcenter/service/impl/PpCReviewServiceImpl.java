package com.zeroone.star.bizcenter.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.PpCReview;
import com.zeroone.star.bizcenter.mapper.PpCReviewMapper;
import com.zeroone.star.bizcenter.service.IPpCReviewService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCReviewDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCReviewQuery;
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
interface ReviewTransfer{
    /**
     * @Description:  类型转换器，用于DO转DTO
     * @Param: PpCTask
     * @return:  PpCTaskDTO
     * @Author: hamhuo
     * @Date:
     */
    PpCReviewDTO review2Dto(PpCReview ppCReview);
}
@Service
public class PpCReviewServiceImpl extends ServiceImpl<PpCReviewMapper, PpCReview> implements IPpCReviewService {

    @Resource
    private ReviewTransfer reviewTransfer;

    @Override
    public PageDTO<PpCReviewDTO> selectReviewByPerson(PpCReviewQuery query) {
        //创建分页模型
        Page<PpCReview> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构造查询条件
        QueryWrapper<PpCReview> queryWrapper = new QueryWrapper<>();

        // person必需，加入查询条件
        queryWrapper.eq("xperson", query.getPerson());

        // title可以为空，判断后再加入查询条件
        if (StringUtils.isNotBlank(query.getKeyValue())) {
            queryWrapper.like("xtitle", query.getKeyValue());
        }

        //执行查询
        Page<PpCReview> result = baseMapper.selectPage(page, queryWrapper);
        return PageDTO.create(result,reviewTransfer::review2Dto);
    }
}
