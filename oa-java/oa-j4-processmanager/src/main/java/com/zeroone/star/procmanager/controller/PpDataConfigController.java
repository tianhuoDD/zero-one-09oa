package com.zeroone.star.procmanager.controller;

import com.zeroone.star.project.j4.procmanager.dataConfig.DataConfigApis;
import com.zeroone.star.procmanager.service.IPpDataConfigService;
import com.zeroone.star.project.dto.j4.procmanager.AddDataConfigDto.AddDataConfigDto;
import com.zeroone.star.project.dto.j4.procmanager.UpdateDataConfigDto.UpdateDataConfigDto;
import com.zeroone.star.project.dto.j4.procmanager.DeleteDataConfigDto.DeleteDataConfigDto;
import com.zeroone.star.project.dto.j4.procmanager.data.properties.CategoryDTO;
import com.zeroone.star.project.dto.j4.procmanager.data.properties.DetailedConfigurationDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.procmanager.AddApplicationVo.AddDataConfigVo;
import com.zeroone.star.project.vo.j4.procmanager.UpdateDataConfigVo.UpdateDataConfigVo;
import com.zeroone.star.project.vo.j4.procmanager.DeleteDataConfigVo.DeleteDataConfigVo;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.CategoryVO;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.DetailedConfigurationVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 数据配置管理 前端控制器
 * </p>
 *
 * @author j4
 * @since 2024-10-28
 */
@RestController
@RequestMapping("/j4-procmanager/data-config")
@Api(tags = "数据配置管理")
public class PpDataConfigController implements DataConfigApis {
    @Resource
    private IPpDataConfigService ppDataConfigService;

    @Override
    @ApiOperation("获取数据配置列表")
    @GetMapping("category")
    public JsonVO<List<CategoryVO>> queryCategoryAll(CategoryDTO categoryDTO) {
        return ppDataConfigService.queryCategoryAll(categoryDTO);
    }

    @Override
    @ApiOperation("获取数据配置详细")
    @GetMapping("category-data")
    public JsonVO<DetailedConfigurationVO> queryDataAll(DetailedConfigurationDTO detailedConfigurationDTO) {
        return ppDataConfigService.queryDataAll(detailedConfigurationDTO);
    }

    @Override
    @PostMapping("add")
    @ApiOperation("新增数据配置")
    public AddDataConfigVo addDataConfig(@RequestBody AddDataConfigDto dto) {
        return ppDataConfigService.addDataConfig(dto);
    }

    @Override
    @PutMapping("update")
    @ApiOperation("更新数据配置")
    public UpdateDataConfigVo updateDataConfig(@RequestBody UpdateDataConfigDto dto) {
        return ppDataConfigService.updateDataConfig(dto);
    }

    @Override
    @DeleteMapping("delete")
    @ApiOperation("删除数据配置")
    public DeleteDataConfigVo deleteDataConfig(@RequestBody DeleteDataConfigDto dto) {
        return ppDataConfigService.deleteDataConfig(dto);
    }
}