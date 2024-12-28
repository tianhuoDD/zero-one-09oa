package com.zeroone.star.cmshome.controller;

import com.zeroone.star.cmshome.service.IGetColumnListService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.cmshome.GetColumnListDTO;
import com.zeroone.star.project.j5.cmshome.GetColumnListApis;
import com.zeroone.star.project.query.j5.cmshome.GetColumnListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;
/**
 * @Description: 栏目-获取栏目列表(应用卡片)
 * @Param:
 * @return:
 * @Author: huangyakang
 * @Date:
 */
@RestController
@RequestMapping("cmshome")
@Api(tags = "获取栏目列表")
@RequiredArgsConstructor
public class GetColumnListController implements GetColumnListApis {

    private final IGetColumnListService getColumnListService;

    @GetMapping("column/list")

    @ApiOperation("获取栏目列表")
    @Override
    public JsonVO<PageDTO<GetColumnListVO>> getColumnList(GetColumnListDTO getColumnListDTO) {
        // 分页查询栏目列表
        PageDTO<GetColumnListVO> columnListVOPageDTO = getColumnListService.page(getColumnListDTO);
        return JsonVO.success(columnListVOPageDTO);
    }
}
