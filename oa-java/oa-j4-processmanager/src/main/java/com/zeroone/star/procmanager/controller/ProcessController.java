package com.zeroone.star.procmanager.controller;

import com.zeroone.star.procmanager.service.IProcessService;
import com.zeroone.star.project.dto.j4.process.ModifyProcessOrAddProcessDTO;
import com.zeroone.star.project.j4.process.ProcessApis;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.vo.j4.process.DeleteProcessVO;
import com.zeroone.star.project.vo.j4.process.ModifyProcessOrAddProcessVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author awei qy
 * @since 2024-10-21
 */
@RestController
@RequestMapping("/process")
@Api(tags = "流程相关接口")
public class ProcessController implements ProcessApis {

    @Resource
    IProcessService processServiceImpl;


    @PostMapping("add-process")
    @ApiOperation("新增流程")
    @Override
    public JsonVO<ModifyProcessOrAddProcessVO> addProcess(ModifyProcessOrAddProcessDTO modifyProcessOrAddProcessDTO) {
        return processServiceImpl.saveProcess(modifyProcessOrAddProcessDTO);
    }

    @DeleteMapping("/deleteProcess")
    @ApiOperation(value = "删除流程")
    @Override
    public JsonVO<DeleteProcessVO> deleteProcess(@RequestParam(value = "id") String id) {
        return JsonVO.success(processServiceImpl.deleteProcess(id));
    }

    @PutMapping("/ UpdateProcess")
    @ApiOperation(value = "更新或者新添流程")
    @Override
    public JsonVO<ModifyProcessOrAddProcessVO> modifyProcessOrAddProcess(ModifyProcessOrAddProcessDTO modifyProcessOrAddProcessDTO) {
        return JsonVO.success(processServiceImpl.modifyProcessOrAddProcess(modifyProcessOrAddProcessDTO));
    }
}

