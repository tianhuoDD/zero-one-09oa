package com.zeroone.star.project.j1.system;

import com.zeroone.star.project.dto.j1.systemhome.DiskFileDTO;
import com.zeroone.star.project.dto.j1.systemhome.FileStaticsDTO;
import com.zeroone.star.project.query.j1.systemhome.DiskFileQuery;
import com.zeroone.star.project.query.j1.systemhome.FileStaticsQuery;
import com.zeroone.star.project.query.j1.systemhome.SchedulePreviewQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemhome.DiskFileVO;
import com.zeroone.star.project.vo.j1.systemhome.SchedulePreviewVO;

/**
 * 系统首页接口
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/21
 */
public interface SystemHomeApis {

    /**
     * 查询网盘文件信息（查询最近五条文件操作）
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<DiskFileVO> queryDiskFileInfo(DiskFileQuery query);

    /**
     * 文件统计（查询文件统计信息）
     * @param query 查询条件
     * @return 文件统计结果
     */
    JsonVO<FileStaticsDTO> queryFileStatistics(FileStaticsQuery query);

    /**
     * 日程预览（查询需要提醒的日程）
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<SchedulePreviewVO> querySchedulePreview(SchedulePreviewQuery query);


}
