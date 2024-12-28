package com.zeroone.star.systemhome.controller;

import com.zeroone.star.project.j1.system.home.ProcessInfoApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.system.home.ProcessInfoVo;
import com.zeroone.star.systemhome.service.impl.ProcessInfoServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 描述：流程信息controller层
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1.兔子
 * @version 1.0.0
 */
@RestController
@RequestMapping("systemhome")
@Api(tags = "流程信息")
public class ProcessInfoController implements ProcessInfoApis {
    @Autowired
    private ProcessInfoServiceImpl processInfo;
    /**
     * 根据用户id获得流程相关信息，顺序为待办，已办，待阅，已阅，草稿
     * @param id 用户id
     * @return 获JsonVO封装，获取到的流程信息,获得待办，已办，待阅，已阅，草稿的数量
     */
    @GetMapping("query-process-info")
    @Override
    @ApiOperation("获得流程信息")
    public JsonVO<ProcessInfoVo> queryProcessInfo(String id){
        ProcessInfoVo result= processInfo.getProcessInfo(id);
        return JsonVO.success(result);
    }
}
