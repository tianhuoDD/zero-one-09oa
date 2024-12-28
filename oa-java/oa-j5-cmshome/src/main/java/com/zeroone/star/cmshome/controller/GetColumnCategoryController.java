package com.zeroone.star.cmshome.controller;

import com.zeroone.star.project.j5.cmshome.GetColumnCategoryApis;
import com.zeroone.star.cmshome.service.IGetColumnCategoryService;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnCategoryVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @Description: 栏目-获取所有栏目类型
 * @Param:
 * @return:
 * @Author: chensimeng
 * @Date:
 */
@RestController
@RequestMapping("cmshome/column")
@Api(tags = "获取所有栏目类型")
@RequiredArgsConstructor
public class GetColumnCategoryController implements GetColumnCategoryApis {

    private final IGetColumnCategoryService getColumnCategoryService;

    @GetMapping("/category")
    @ApiOperation("获取所有栏目类型")
    @Override
    public JsonVO<List<GetColumnCategoryVO>> getColumnCategory() {
        List<GetColumnCategoryVO> list = getColumnCategoryService.getColumnCategory();
        return JsonVO.success(list);
    }
}
/**/
