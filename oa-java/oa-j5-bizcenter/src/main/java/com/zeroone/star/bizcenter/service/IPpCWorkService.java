package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.PpCWork;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCTaskDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCWorkDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCTaskQuery;
import com.zeroone.star.project.query.j5.bizcenter.PpCWorkQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */
public interface IPpCWorkService extends IService<PpCWork> {
    public PageDTO<PpCWorkDTO> selectWorkByPerson (PpCWorkQuery ppCWorkQuery);

}
