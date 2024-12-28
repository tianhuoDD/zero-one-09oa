package com.zeroone.star.systemhome.service;

import com.zeroone.star.project.dto.j1.systemhome.SchedulePreviewDTO;

import java.util.Date;
import java.util.List;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/26
 */
public interface SchedulePreviewService {
    /**
     * 查询指定日期的日程
     * @param chooseDate 查询日期
     * @param person 用户
     * @return 查询结果
     */
    List<SchedulePreviewDTO> listSchedulePreview(Date chooseDate, String person);
}
