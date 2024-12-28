package com.zeroone.star.columnsetting.controller;


import com.zeroone.star.columnsetting.service.ICmsAppndictService;
import com.zeroone.star.columnsetting.service.IDataConfigService;
import com.zeroone.star.project.j3.datacofig.DataConfigApis;
import com.zeroone.star.project.j3.datacofig.dto.DataConfigDTO;
import com.zeroone.star.project.j3.dataconfig.vo.dataConfigDetailVO;
import com.zeroone.star.project.j3.dataconfig.vo.dataConfigVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author luo
 * @since 2024-10-20
 */
@Slf4j
@Api(tags = "数据配置相关接口")
@RestController
@RequestMapping("/dataconfig")
public class DataConfigController implements DataConfigApis {

    @Resource
    private IDataConfigService dataConfigService;

    /**
     * 添加数据配置接口
     *
     * @param dataConfigDTO 接收的数据配置参数
     * @return 数据配置的id
     */
    @PostMapping("/add")
    @ApiOperation("添加配置接口")
    @Override
    public JsonVO<String> addDataConfig(DataConfigDTO dataConfigDTO) {
        //插入的数据配置id
       String id = dataConfigService.saveDataConfig(dataConfigDTO);
        return JsonVO.success(id);
    }

    /**
     * 修改配置接口
     *
     * @param dataConfigDTO 接收的数据配置参数
     * @return 数据配置的id
     */
    @ApiOperation("修改配置接口")
    @PutMapping("/modify")
    @Override
    public JsonVO<String> modifyDataConfig(DataConfigDTO dataConfigDTO) {
       String dictId = dataConfigService.update(dataConfigDTO);
        return JsonVO.success(dictId);
    }

    /**
     * 删除配置
     *
     * @param id 数据配置的id
     * @return 删除的数据配置的id
     */
    @ApiOperation("删除配置")
    @DeleteMapping("/delete-by-id/{id}")
    @Override
    public JsonVO<String> removeDataConfig(@PathVariable String id) {
        //根据数据配置id删除数据
        log.info("根据数据配置id删除数据:{}",id);
        String result = dataConfigService.removeById(id);
        return JsonVO.success(result);
    }


    @Resource
    private ICmsAppndictService cmsAppndictService;

    /**
     * 获取数据配置列表
     * @return
     */
    @GetMapping("/query-all")
    @ApiOperation(value = "获取数据配置列表")
    public JsonVO<List<dataConfigVO>> queryDataConfigList() {
        //返回list<dataConfigVO>
        return JsonVO.success(cmsAppndictService.getDataConfigList());
    }

    /**
     * 获取数据配置详细信息
     * @param xid 数据配置要查找的表的ID
     * @return
     */
    @GetMapping("/query-by-id")
    @ApiOperation(value = "获取数据配置详细信息")
    public JsonVO<dataConfigDetailVO> queryDataConfigDetail(String xid) {
        return JsonVO.success(cmsAppndictService.getDataConfig(xid));
    }
}

