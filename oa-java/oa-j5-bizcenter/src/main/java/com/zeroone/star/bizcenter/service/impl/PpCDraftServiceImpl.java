package com.zeroone.star.bizcenter.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.bizcenter.entity.PpCDraft;
import com.zeroone.star.bizcenter.mapper.PpCDraftMapper;
import com.zeroone.star.bizcenter.service.IPpCDraftService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCDraftDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCDraftQuery;

import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
//DO2DTO with mapstruct
interface DraftTransfer {
    //a entrance for mapstruct trans do2dto
    PpCDraftDTO draftDo2Dto(PpCDraft ppCDraft);
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
public class PpCDraftServiceImpl extends ServiceImpl<PpCDraftMapper, PpCDraft> implements IPpCDraftService {

    //notation for mapstruct
    @Resource
    private DraftTransfer draftTransfer;
    @Override
    public PageDTO<PpCDraftDTO> selectDraftByPerson(PpCDraftQuery query) {
        //1.构建分页模型
        Page<PpCDraft> page = new Page<>(query.getPageIndex(), query.getPageSize());

        //2.构建查询条件
        QueryWrapper<PpCDraft> queryWrapper = new QueryWrapper<>();

        // person必需，加入查询条件
        queryWrapper.eq("xperson", query.getPerson());

        // title可以为空，判断后再加入查询条件
        if (StringUtils.isNotBlank(query.getKeyValue())) {
            queryWrapper.like("xtitle", query.getKeyValue());
        }

        //3.执行查询
        Page<PpCDraft> result =  baseMapper.selectPage(page, queryWrapper);

        //DO转DTO
        return PageDTO.create(page, draftTransfer::draftDo2Dto);
    }
}
