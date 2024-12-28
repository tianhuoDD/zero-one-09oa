package com.zeroone.star.bizcenter.controller;

import com.zeroone.star.bizcenter.service.*;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.*;
import com.zeroone.star.project.j5.bizcenter.QueryProcessListApis;
import com.zeroone.star.project.query.j5.bizcenter.*;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @program: oa-java
 * @description: 流程详情controller，办公中心首页列表查询
 * @author: hamhuo
 * @create: 2024-10-19 23:01
 **/

@RestController
@RequestMapping("bizcenter/query-all-process")
@Api(tags = "获取流程列表")
public class QueryProcessListController implements QueryProcessListApis {

    @Resource
    IPpCTaskService ppCTaskService;
    @Resource
    IPpCReviewService ppCReviewService;
    @Resource
    IPpCReadService ppCReadService;
    @Resource
    IPpCDraftService ppCDraftService;
    @Resource
    private IPpCTaskcompletedService ppCTaskcompletedServiceImpl;
    @Resource
    private IPpCReadcompletedService ppCReadcompletedServiceImpl;
    @Resource
    private IPpCWorkService ppCWorkServiceImpl;

    @ApiOperation(value = "获取流程列表-待办")
    @PostMapping("task")
    @Override
    public JsonVO<PageDTO<PpCTaskDTO>> selectTaskListByPerson(PpCTaskQuery ppCTaskQuery) {
        return JsonVO.success(ppCTaskService.selectTaskByPerson(ppCTaskQuery));
    }

    @ApiOperation(value = "获取流程列表-参阅")
    @PostMapping("review")
    @Override
    public JsonVO<PageDTO<PpCReviewDTO>> selectReviewListByPerson(PpCReviewQuery ppCReviewQuery) {
        return JsonVO.success(ppCReviewService.selectReviewByPerson(ppCReviewQuery));
    }

    @ApiOperation(value = "获取流程列表-待阅")
    @PostMapping("read")
    @Override
    public JsonVO<PageDTO<PpCReadDTO>> selectReadListByPerson(PpCReadQuery ppCReadQuery) {
        return JsonVO.success(ppCReadService.selectReadByPerson(ppCReadQuery));
    }

    @ApiOperation(value = "获取流程列表-草稿")
    @PostMapping("draft")
    @Override
    public JsonVO<PageDTO<PpCDraftDTO>> selectDraftListByPerson(PpCDraftQuery ppCDraftQuery) {
        return JsonVO.success(ppCDraftService.selectDraftByPerson(ppCDraftQuery));
    }

    @ApiOperation(value = "获取流程列表-已办")
    @PostMapping("taskcompleted")
    @Override
    public JsonVO<PageDTO<PpCTaskcompletedDTO>> selectTaskcompletedListByPerson(PpCTaskcompletedQuery ppCTaskCompletedQuery) {
        return JsonVO.success(ppCTaskcompletedServiceImpl.selectTaskCompleteByPerson(ppCTaskCompletedQuery));
    }

    @ApiOperation(value = "获取流程列表-已阅")
    @PostMapping("readcompleted")
    @Override
    public JsonVO<PageDTO<PpCReadcompletedDTO>> selectReadcompletedListByPerson(PpCReadcompletedQuery ppCReadcompletedQuery) {
        return JsonVO.success(ppCReadcompletedServiceImpl.selectReadcompletedByPerson(ppCReadcompletedQuery));
    }

    @ApiOperation(value = "获取流程列表-我创建的")
    @PostMapping("work")
    @Override
    public JsonVO<PageDTO<PpCWorkDTO>> selectWorkListByPerson(PpCWorkQuery ppCWorkQuery) {
        return JsonVO.success(ppCWorkServiceImpl.selectWorkByPerson(ppCWorkQuery));
    }
}
