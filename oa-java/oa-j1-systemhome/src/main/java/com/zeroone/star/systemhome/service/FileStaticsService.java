package com.zeroone.star.systemhome.service;

import com.zeroone.star.project.dto.j1.systemhome.FileStaticsDTO;

import java.util.Date;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/25
 */
public interface FileStaticsService {

    /**
     * 统计一定时间范围内 每周的文件上传、删除、共享、发送数量
     * @param xperson 用户名
     * @param startDate 开始日期
     * @param endDate 结束日期
     * @return 统计结果
     */
    FileStaticsDTO countFileStatistics(String xperson, Date startDate, Date endDate);
}
