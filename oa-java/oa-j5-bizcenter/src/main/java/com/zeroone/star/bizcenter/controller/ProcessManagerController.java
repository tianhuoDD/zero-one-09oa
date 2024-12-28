package com.zeroone.star.bizcenter.controller;



import com.zeroone.star.project.j5.bizcenter.ProcessManagerApis;
import com.zeroone.star.project.query.j5.bizcenter.ProcessManagementQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessRecordsVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/process")
@Api(tags = "流程管理相关接口")
public class ProcessManagerController implements ProcessManagerApis {

    @PostMapping("/bizcenter/process-flow")
    @ApiOperation("查询流程流转数据")
    @Override
    public JsonVO<ProcessRecordsVO> queryProcess(@RequestBody ProcessManagementQuery dataQuery) {

        return JsonVO.success(new ProcessRecordsVO());
    }

    @PostMapping("/bizcenter/process-records")
    @ApiOperation("查询流程记录数据")
    @Override
    public JsonVO<List<ProcessRecordsVO>> queryProcessRecords(@RequestBody ProcessManagementQuery dataQuery) {
        List<ProcessRecordsVO> list = new ArrayList<>();
        return JsonVO.success(list);
    }

}