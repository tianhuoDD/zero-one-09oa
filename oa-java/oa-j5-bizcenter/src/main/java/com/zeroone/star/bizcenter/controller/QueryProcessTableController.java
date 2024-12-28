package com.zeroone.star.bizcenter.controller;

import com.zeroone.star.project.j5.bizcenter.QueryProcessTableApis;
import com.zeroone.star.bizcenter.service.ProcessTableService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
/**
 * @Description: 流程详情-获取流程表单
 * @Param:
 * @return:
 * @Author: tankeke
 * @Date:
 */
@RestController
@Api(tags = "获取流程表单")
@Slf4j
@RequestMapping("/bizcenter/form-search")
public class QueryProcessTableController implements QueryProcessTableApis {

    /**
     * 通过表单格式xid获取表格
     * @param xid
     * @return
     */
    @Resource
    private ProcessTableService service;

    @GetMapping("/form-by-id")
    @ApiOperation("查询流程表格式")
    @Override
    public JsonVO<ProcessFormVO> queryProcessTable(String xid) {
        log.info("通过xid获取流程表单格式，{}",xid);
        return JsonVO.success(service.getProcessTableByXid(xid));
    }

}
