package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.PpCDraft;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCDraftDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCReadDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCDraftQuery;
import com.zeroone.star.project.query.j5.bizcenter.PpCReadQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */
public interface IPpCDraftService extends IService<PpCDraft> {

    //查询草稿列表
    PageDTO<PpCDraftDTO> selectDraftByPerson(PpCDraftQuery query);
}
