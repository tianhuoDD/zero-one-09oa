package com.zeroone.star.oaj2sysbasic.controller;

import com.zeroone.star.oaj2sysbasic.service.SystemBasicInformationService;
import com.zeroone.star.project.j2.system.basic.information.SystemInformationApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.basic.information.SystemBasicInformationVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @ClassName: SystemBasicInformationController
 * @Package: com.zeroone.star.oaj2sysbasic.controller
 * @Description: 系统基本信息控制器层
 * @Author: zk
 * @Create: 2024/10/20 - 下午5:27
 */
@RestController
@RequestMapping("sysbasic/system-info")
@Api(tags = "系统信息")
public class SystemBasicInformationController implements SystemInformationApis {
    @Resource
    private SystemBasicInformationService service;

    @Override
    @GetMapping
    @ApiOperation("获取系统基本信息")
    public JsonVO<SystemBasicInformationVO> queryBasicInfo() {
        return JsonVO.success(service.getSysBasicInfo());
    }

    @Override
    @PutMapping("modify-title")
    @ApiOperation("修改系统名称")
    public JsonVO<String> modifySystemTitle(String systemTitle) {
        return JsonVO.success(service.updateSysTitle(systemTitle));
    }

    @Override
    @PutMapping("modify-footer")
    @ApiOperation("修改系统副标题")
    public JsonVO<String> modifySystemFooter(String systemFooter) {
        return JsonVO.success(service.updateSysFooter(systemFooter));
    }
}
