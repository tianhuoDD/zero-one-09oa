package com.zeroone.star.procmanager.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.process.PpEProcessPageDTO;
import com.zeroone.star.project.j4.process.ProcessQueryApis;
import com.zeroone.star.project.query.j4.pocess.PpEProcessQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.procmanager.service.IPpEProcessService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;
import java.util.Map;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author qy
 * @since 2024-10-21
 */
@RestController
@RequestMapping("pp-eprocess")
@Api(tags = "流程类型及分页")
public class PpEProcessController implements ProcessQueryApis{

    @Resource
    IPpEProcessService ppEProcessService;

    @GetMapping("query-by-category")
    @ApiOperation(value = "查询类型")
    @Override
    public JsonVO<List<Map<String, Object>>> countByCategory() {
        return JsonVO.success(ppEProcessService.countCategory());
    }

    @GetMapping("query-all")
    @ApiOperation(value = "分页查询所有")
    @Override
    public JsonVO<PageDTO<PpEProcessPageDTO>> queryAll(PpEProcessQuery condition) {
        return JsonVO.success(ppEProcessService.listAll(condition));
    }


}

