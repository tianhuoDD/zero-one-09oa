package com.zeroone.star.bizcenter.controller;

import com.zeroone.star.project.j5.bizcenter.GetProcessMonitoringApis;
import com.zeroone.star.bizcenter.service.GetProcessMonitoringService;
import com.zeroone.star.project.vo.JsonVO;


import com.zeroone.star.project.vo.j5.bizcenter.ComplexVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;


/**
 * @Description: 流程管理-流程监控
 * @Param:
 * @return:
 * @Author: xiongjian
 * @Date:
 */
@RestController
@Api(tags = "流程监控")
@RequestMapping("bizcenter/jaxrs/process")
@Slf4j
@Validated
public class GetProcessMonitoringController implements GetProcessMonitoringApis {


    @Resource
    private GetProcessMonitoringService getProcessMonitoringService;

    @ApiOperation("流程监控")
    @GetMapping("{flag}/complex")
    @Override
    public JsonVO<ComplexVO> getComplex(@PathVariable String flag) {
        log.info("流程监控:id::{}",flag);
        ComplexVO complexVO  = getProcessMonitoringService.getComplex(flag);
        return JsonVO.success(complexVO);
    }

}
