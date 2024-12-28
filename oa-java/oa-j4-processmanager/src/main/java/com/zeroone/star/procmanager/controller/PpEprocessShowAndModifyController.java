package com.zeroone.star.procmanager.controller;

import com.zeroone.star.procmanager.service.IPpEprocessShowAndModifyService;
import com.zeroone.star.project.dto.j4.process.ModifyProcessDTO;
import com.zeroone.star.project.dto.j4.process.PpEProcessDetailDto;
import com.zeroone.star.project.j4.process.ProcessShowAndModifyApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/process-sam")
@Api(tags = "流程相关接口SAM")
public class PpEprocessShowAndModifyController implements ProcessShowAndModifyApis {
@Resource
private IPpEprocessShowAndModifyService ppEprocessShowAndModifyService;
    @Override
    @ApiOperation("查询流程详情")
    @GetMapping("/show")
    public JsonVO<List<PpEProcessDetailDto>> ProcessShowDetail(String id) {
        List<PpEProcessDetailDto> ppEProcessDetailDto = ppEprocessShowAndModifyService.ProcessShowDetail(id);
        return JsonVO.success(ppEProcessDetailDto);
    }

    @Override
    @ApiOperation("修改流程")
    @PutMapping("/modify")
    public JsonVO<String> modifyProcess(ModifyProcessDTO ppEProcessDTO) {
        ppEprocessShowAndModifyService.modifyProcess(ppEProcessDTO);
        return JsonVO.success("修改成功");


    }
}
