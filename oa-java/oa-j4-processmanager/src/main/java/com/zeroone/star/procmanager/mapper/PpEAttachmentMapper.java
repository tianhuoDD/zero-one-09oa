package com.zeroone.star.procmanager.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.procmanager.entity.PpEFile;
import org.apache.ibatis.annotations.Mapper;


@Mapper
public interface PpEAttachmentMapper extends BaseMapper<PpEFile> {
    /**
     * 获取附件列表
     * @param page
     * @param queryWrapper
     * @return
     */
    Page<PpEFile> selectPage(Page<PpEFile> page, QueryWrapper<PpEFile> queryWrapper);


    /**
     * 获取附件详情
     * @param id
     * @return
     */
    PpEFile selectById(int id);

}
