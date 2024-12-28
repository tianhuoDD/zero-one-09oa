package com.zeroone.star.systemhome.controller;

import com.zeroone.star.project.dto.j1.systemhome.DiskFileDTO;
import com.zeroone.star.project.dto.j1.systemhome.FileStaticsDTO;
import com.zeroone.star.project.dto.j1.systemhome.SchedulePreviewDTO;
import com.zeroone.star.project.j1.system.SystemHomeApis;
import com.zeroone.star.project.query.j1.systemhome.DiskFileQuery;
import com.zeroone.star.project.query.j1.systemhome.FileStaticsQuery;
import com.zeroone.star.project.query.j1.systemhome.SchedulePreviewQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemhome.DiskFileVO;
import com.zeroone.star.project.vo.j1.systemhome.SchedulePreviewVO;
import com.zeroone.star.systemhome.service.DiskFileInfoService;
import com.zeroone.star.systemhome.service.FileStaticsService;
import com.zeroone.star.systemhome.service.SchedulePreviewService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.UUID;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/21
 */
@RestController
@RequestMapping("systemhome")
@Api(tags = "系统首页")
public class SystemhomeController implements SystemHomeApis {

    @Resource
    DiskFileInfoService diskFileInfoService;

    @Resource
    FileStaticsService fileStaticsService;

    @Resource
    SchedulePreviewService schedulePreviewService;

    private SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

    @GetMapping("queryDiskFileInfo")
    @ApiOperation("查询文件信息列表")
    @Override
    public JsonVO<DiskFileVO> queryDiskFileInfo(DiskFileQuery query) {
        List<DiskFileDTO> diskFileDTOList = diskFileInfoService.listDiskFileInfo(query.getXperson());
        DiskFileVO diskFileVO = new DiskFileVO();
        diskFileVO.setDiskFileDTOList(diskFileDTOList);
        diskFileVO.setXid(UUID.randomUUID().toString());
        return JsonVO.success(diskFileVO);
    }

    @SneakyThrows
    @GetMapping("queryFileStatistics")
    @ApiOperation("文件统计")
    @Override
    public JsonVO<FileStaticsDTO> queryFileStatistics(FileStaticsQuery query) {
        if (query.getStartDate().compareTo(query.getEndDate()) >= 0) {
            return new JsonVO<>(400, "开始时间不能大于结束时间", null);
        }
        //将字符串转为日期格式
        Date startDate = sdf.parse(query.getStartDate());
        Date endDate = sdf.parse(query.getEndDate());
        FileStaticsDTO fileStaticsDTO = fileStaticsService.countFileStatistics(query.getXperson(), startDate, endDate);
        return JsonVO.success(fileStaticsDTO);
    }

    @SneakyThrows
    @GetMapping("querySchedulePreview")
    @ApiOperation("日程预览")
    @Override
    public JsonVO<SchedulePreviewVO> querySchedulePreview(SchedulePreviewQuery query) {
        Date date = sdf.parse(query.getChooseDate());
        List<SchedulePreviewDTO> schedulePreviewDTOList = schedulePreviewService.listSchedulePreview(date, query.getPerson());
        SchedulePreviewVO schedulePreviewVO = new SchedulePreviewVO();
        schedulePreviewVO.setPreviewList(schedulePreviewDTOList);
        schedulePreviewVO.setXid(UUID.randomUUID().toString());
        return JsonVO.success(schedulePreviewVO);
    }
}
