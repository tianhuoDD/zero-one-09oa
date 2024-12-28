package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.PpCTaskcompleted;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCTaskcompletedDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCTaskcompletedQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-29
 */
public interface IPpCTaskcompletedService extends IService<PpCTaskcompleted> {
    public PageDTO<PpCTaskcompletedDTO> selectTaskCompleteByPerson(PpCTaskcompletedQuery ppCTaskcompletedQuery);
}
