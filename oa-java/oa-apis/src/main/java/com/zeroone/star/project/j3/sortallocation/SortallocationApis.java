package com.zeroone.star.project.j3.sortallocation;

import com.zeroone.star.project.j3.sortallocation.dto.CategoryDTO;
import com.zeroone.star.project.j3.sortallocation.vo.CategoryVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;



public interface SortallocationApis
{
    /**
     * 获取栏目分类列表
     * @param query 查询条件
     * @return 栏目分类列表
     */
    public JsonVO<List<CategoryVO>> queryAll(String appId);

    /**
     * 修改栏目分类
     * @param dto 栏目分类信息
     * @return 修改结果
     */
    public JsonVO<CategoryDTO> modifyCategory(CategoryDTO dto);

    /**
     * 添加栏目分类
     * @param name  栏目分类名称
     * @param appId 父级栏目ID
     * @return id 栏目分类ID
     */
    public JsonVO<String> modifyCategory(String name, String appId );

    /**
     * 删除栏目分类
     * @param id 栏目分类名称
     * @return 是否删除成功
     */
    public JsonVO<Boolean> removeCategory(String id);
}
