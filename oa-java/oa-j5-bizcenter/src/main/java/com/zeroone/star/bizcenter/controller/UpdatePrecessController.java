package com.zeroone.star.bizcenter.controller;

import com.zeroone.star.bizcenter.service.UpdatePrecessService;
import com.zeroone.star.project.dto.j5.bizcenter.PrecessingDTO;
import com.zeroone.star.project.dto.j5.bizcenter.ReplaceDTO;
import com.zeroone.star.project.dto.j5.bizcenter.RerouteDTO;
import com.zeroone.star.project.dto.j5.bizcenter.RollbackDTO;
import com.zeroone.star.project.j5.bizcenter.UpdatePrecessApis;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.vo.j5.bizcenter.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.Map;

/**
 * @Description: 流程管理-修改流程
 * @Param:
 * @return:
 * @Author: xiongjian
 * @Date:
 */
@RestController
@RequestMapping("bizcenter")
@Api(tags = "修改流程")
public class UpdatePrecessController implements UpdatePrecessApis {


    @Resource
    private UpdatePrecessService updatePrecessService;


    @ApiOperation("回溯流程")
    @PutMapping("/work/v2/{id}/rollback")
    public JsonVO<RollbackVO> Rollback(@PathVariable String id, RollbackDTO rollbackDTO) {
        // TODO 前提得具有管理员权限
        return JsonVO.success(updatePrecessService.rollBack(id, rollbackDTO));
    }


    @PutMapping("/work/v2/{id}/reroute")
    @ApiOperation("工作调度")
    @Override
    public JsonVO<RerouteVO> V2Reroute(@PathVariable String id , @RequestBody RerouteDTO rerouteDTO) {
        // TODO 前提得具有管理员权限
        return  JsonVO.success(updatePrecessService.reroute(id, rerouteDTO));
    }


    @PostMapping("/task/{id}/processing")
    @ApiOperation("继续流转")
    @Override
    public JsonVO<RecordVO> processing(@PathVariable String id, @RequestBody PrecessingDTO precessingDTO) {
        RecordVO recordVO = updatePrecessService.updateProcessing(id, precessingDTO);
        return JsonVO.success(recordVO);
    }

    @PutMapping("/work/v2/{id}/retract")
    @ApiOperation("撤回流程")
    @Override
    public JsonVO<RetractVO> V2Retract(@PathVariable String id) {
        return JsonVO.success(new RetractVO());
    }

    @PutMapping("/task/v2/{id}/reset")
    @ApiOperation("重置处理人")
    @Override
    public JsonVO<ReplaceVO> ResetWorkPerson(@PathVariable String id, @RequestBody ReplaceDTO replaceDTO) {
        ReplaceVO replaceVO = updatePrecessService.resetWorkPerson(id, replaceDTO);
        return JsonVO.success(replaceVO);
    }

    @PostMapping("/snap/work/{workId}/type/abandoned")
    @ApiOperation("对工作进行快照,并标记为废弃.")
    @Override
    public JsonVO<String> DeleteWork(@PathVariable String workId) {
        String snapID = updatePrecessService.abandonedWork(workId);
        return JsonVO.success(snapID);
    }

    @ApiOperation("删除文件")
    @DeleteMapping("/work/{id}/close/check")
    @Override
    public JsonVO<Boolean> closeCheck(@PathVariable String id) {
        Boolean value = updatePrecessService.closeWork(id);
        return JsonVO.success(value);
    }

    @ApiOperation("修改工作业务数据")
    @PutMapping("/data/work/{id}")
    @Override
    public JsonVO<String> updateWithWork(@PathVariable String id, @RequestBody Map<String, Object> params) {
        updatePrecessService.updateWorkData(id,params);
        return JsonVO.success("修改成功!");
    }
}
