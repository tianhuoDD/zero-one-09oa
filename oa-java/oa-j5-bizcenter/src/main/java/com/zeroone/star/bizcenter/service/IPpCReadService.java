package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.PpCRead;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCReadDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCReadQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */
public interface IPpCReadService extends IService<PpCRead> {

    //查询待阅列表
    PageDTO<PpCReadDTO> selectReadByPerson(PpCReadQuery query);
}
