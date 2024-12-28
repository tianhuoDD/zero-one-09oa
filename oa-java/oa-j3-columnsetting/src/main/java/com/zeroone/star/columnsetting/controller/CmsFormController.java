package com.zeroone.star.columnsetting.controller;

import cn.hutool.core.util.ObjectUtil;
import com.zeroone.star.columnsetting.service.ICmsFormService;
import com.zeroone.star.project.j3.colunAttribute.ColumnAttributeApis;
import com.zeroone.star.project.j3.formattribute.dto.ColumnFormDTO;
import com.zeroone.star.project.j3.formattribute.vo.ColumnFormVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import javax.validation.constraints.NotNull;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author lenyan
 * @since 2024-10-19
 */
@RestController
@RequestMapping("/form")
@Api(tags = "栏目表单管理")
@Slf4j
public class CmsFormController implements ColumnAttributeApis {

    @Resource
    private ICmsFormService cmsFormService;

    /**
     * 添加栏目表单
     * @param columnFormDTO
     * @return
     */
    @ApiOperation(value = "添加栏目表单")
    @PostMapping("/add-form")
    public JsonVO<ColumnFormVO> addColumnForm(@RequestBody ColumnFormDTO columnFormDTO) {
        log.info("添加栏目表单参数为：{}", columnFormDTO);
        if(ObjectUtil.isEmpty(columnFormDTO)) {
            log.error("栏目表单参数为空");
        }
        return cmsFormService.addColumnForm(columnFormDTO);
    }

    /**
     * 删除栏目表单
     * @param id
     * @return
     */
    @ApiOperation(value = "删除栏目表单")
    @DeleteMapping("/delete/{id}")
    public JsonVO<Boolean> deleteColumnForm(@NotNull(message = "id不能为空")
                                                @PathVariable String id) {
        log.info("删除栏目表单参数为：{}", id);
        if(ObjectUtil.isEmpty(id)) {
            log.error("栏目表单id为空");
        }
        return cmsFormService.deleteColumnForm(id);
    }

    /**
     * 修改栏目表单
     * @param cmsFormDTO
     * @return
     */
    @ApiOperation(value = "修改栏目表单")
    @PostMapping("/update")
    public JsonVO<ColumnFormVO> modifyColumnForm(@RequestBody @Valid ColumnFormDTO cmsFormDTO){
        log.info("修改栏目表单参数为：{}", cmsFormDTO);
        return cmsFormService.modifyColumnForm(cmsFormDTO);
    }


    /**
     * 获取栏目表单详情
     * @param id
     * @return
     */
    @ApiOperation(value = "获取栏目表单详情")
    @GetMapping("/query-by-id/{id}")
    public JsonVO<ColumnFormVO> queryColumnForm(@PathVariable("id") String id){
        return cmsFormService.queryColumnForm(id);
    }

    /**
     * 获取栏目表单列表
     * @param id
     * @return
     */
    @ApiOperation(value = "获取栏目表单列表")
    @GetMapping("/query-all/{id}")
    public JsonVO<List<ColumnFormVO>> queryColumnFormList(@PathVariable("id") String id){
        return cmsFormService.queryColumnFormList(id);
    }

}

