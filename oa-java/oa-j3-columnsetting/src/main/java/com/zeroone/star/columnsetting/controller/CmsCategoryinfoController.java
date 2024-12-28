package com.zeroone.star.columnsetting.controller;


import com.zeroone.star.columnsetting.service.ICmsCategoryinfoService;
import com.zeroone.star.project.j3.sortallocation.SortallocationApis;
import com.zeroone.star.project.j3.sortallocation.dto.CategoryDTO;
import com.zeroone.star.project.j3.sortallocation.vo.CategoryVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author jungle
 * @since 2024-10-20
 */
@Api(tags = "分类配置")
@RestController
@RequestMapping("/sortallocation")
public class CmsCategoryinfoController implements SortallocationApis {
    @Resource
    ICmsCategoryinfoService categoryService;

    /**
     * 获取所有栏目类型(已完成)
     * @param  appId 栏目类型
     * @return JsonVO<List<CategoryVO>>
     */
    @ApiOperation(value = "获取所有栏目分类列表")
    @GetMapping("/query-all")
    @Override
    public JsonVO<List<CategoryVO>> queryAll(String appId) {
        return JsonVO.success(categoryService.listAll(appId));
    }

    /**
     * 修改栏目分类
     * @param dto 栏目分类信息
     * @return JsonVO<CategoryVO>
     */
    @ApiOperation(value = "修改栏目分类")
    @PostMapping("/modify-category")
    public JsonVO<CategoryDTO> modifyCategory(@Validated CategoryDTO dto) {
        return JsonVO.success(categoryService.updateCategory(dto));
    }


    /**
     * 添加栏目分类(已完成)
     * @param name  栏目分类名称
     * @param appId 父级栏目ID
     * @return 添加结果
     */
    @ApiOperation(value = "添加栏目分类")
    @PostMapping("/add-category")
    public JsonVO<String> modifyCategory(String name, String appId) {
        //给个建议而已
//        boolean save = categoryService.save(categoryinfo);
//        if(Boolean.TRUE == save) {
//            return JsonVO.success("添加成功");
//        } else {
//            return JsonVO.fail("添加失败");
//        }
        if(categoryService.updateCategory(name,appId)!= null)
            return JsonVO.success(categoryService.updateCategory(name,appId));
        else return JsonVO.fail(categoryService.updateCategory(name,appId));
    }

    /**
     * 删除栏目分类(已完成)
     * @param id 栏目分类名称
     * @return 删除结果
     */
    @ApiOperation(value = "删除栏目分类")
    @DeleteMapping("/remove-category")
    public JsonVO<Boolean> removeCategory(String id) {
        if(categoryService.removeCategorybyId(id))
            return JsonVO.success(categoryService.removeCategorybyId(id));
        else
            return JsonVO.fail(categoryService.removeCategorybyId(id));
    }

}

