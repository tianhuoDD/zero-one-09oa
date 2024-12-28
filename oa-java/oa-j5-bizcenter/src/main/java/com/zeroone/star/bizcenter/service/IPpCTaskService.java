package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.PpCTask;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCTaskDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCTaskQuery;


import java.util.List;

/**
 * <p>
 *  服务类 查询待办接口
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */
public interface IPpCTaskService extends IService<PpCTask> {
     PageDTO<PpCTaskDTO> selectTaskByPerson (PpCTaskQuery ppCTaskQuery);

    /**
     * 保存任务
     * @param currentUser
     * @param processId
     */
     PpCTask saveTask(UserDTO currentUser, String processId);
}
