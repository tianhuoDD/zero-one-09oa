package com.zeroone.star.bizcenter.controller;

import com.zeroone.star.bizcenter.service.CmsAppInfoService;
import com.zeroone.star.bizcenter.service.IPpEFromService;
import com.zeroone.star.bizcenter.service.PPEApplicationService;
import com.zeroone.star.project.j5.bizcenter.AddProcessApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.ApplicationListVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFromVO;
import com.zeroone.star.project.vo.j5.bizcenter.publishProcessVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.List;


/**
 * @Description: 添加流程接口
 * @Param:
 * @return:
 * @Author: zhangyan
 * @Date:
 */
@RestController
@RequestMapping("/bizcenter")
@Api(tags = "添加流程")
@Slf4j
@Validated
public class AddProcessController implements AddProcessApis {

    @Autowired
    private PPEApplicationService ppeApplicationService;
    @Autowired
    private CmsAppInfoService cmsAppInfoService;
    @Autowired
    private IPpEFromService ppEFromService;

    @GetMapping("/query-applications")
    @ApiOperation("获取应用列表")
    public JsonVO<List<ApplicationListVO>> queryApplicationList() {
       log.info("进入queryApplicationList()方法");
        List<ApplicationListVO> applicationListVOS = ppeApplicationService.listApplications();
        return new JsonVO<>(200, "成功", applicationListVOS);
    }

    @GetMapping("/query-publish-process")
    @ApiOperation("查询公共应用")
    public JsonVO<List<publishProcessVO>> queryPublishWithProcess() {
        log.info("进入queryPublishWithProcess()方法");
        List<publishProcessVO> publishProcessVOS = cmsAppInfoService.listPublishProcess();
        return new JsonVO<>(200, "成功", publishProcessVOS);
    }


    @GetMapping("/query-process-form/{id}")
    @ApiOperation("查询流程表单信息")
    public JsonVO<ProcessFromVO> queryProcessFrom(@PathVariable String id) {
        log.info("id={}", id);
        return queryProcessFromById(id);
    }

    public JsonVO<ProcessFromVO> queryProcessFromById(String id) {
        log.info("id={}", id);
        ProcessFromVO processFromVO =  ppEFromService.getFromById(id);
        return new JsonVO<>(200, "成功", processFromVO);
    }



}