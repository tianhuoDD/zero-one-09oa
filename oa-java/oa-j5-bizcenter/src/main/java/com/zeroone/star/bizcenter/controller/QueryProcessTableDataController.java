package com.zeroone.star.bizcenter.controller;


import com.zeroone.star.project.j5.bizcenter.QueryProcessTableDataApis;
import com.zeroone.star.bizcenter.service.ProcessTableDataService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormDataVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @Description: 流程详情-获取流程数据
 * @Param:
 * @return:
 * @Author: tankeke
 * @Date:
 */
@RestController
@Api(tags = "获取流程数据")
@Slf4j
@RequestMapping("/bizcenter/form-search")
public class QueryProcessTableDataController implements QueryProcessTableDataApis {

    @Resource
    private ProcessTableDataService service;


    /**
     * 通过work表的xid 查询流程表格数据
     * @param xid
     * @return
     */
    @GetMapping("/formData-by-id")
    @ApiOperation("查询流程表单数据")
    @Override
    public JsonVO<ProcessFormDataVO> queryProcessTableData(String xid) {
        log.info("获取流程表单数据，通过work的xid：{}",xid);
        return JsonVO.success(service.getProcessTableDataByXid(xid));

    }

}
