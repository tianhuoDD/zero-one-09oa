package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.PpCRead;
import com.zeroone.star.bizcenter.entity.PpCReadcompleted;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCReadDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCReadcompletedDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCReadQuery;
import com.zeroone.star.project.query.j5.bizcenter.PpCReadcompletedQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-29
 */
public interface IPpCReadcompletedService extends IService<PpCReadcompleted> {

    //查询已阅列表
    PageDTO<PpCReadcompletedDTO> selectReadcompletedByPerson(PpCReadcompletedQuery query);

}
