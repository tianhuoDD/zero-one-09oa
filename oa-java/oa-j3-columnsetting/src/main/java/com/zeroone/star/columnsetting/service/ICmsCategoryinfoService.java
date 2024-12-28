package com.zeroone.star.columnsetting.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.columnsetting.entity.CmsCategoryinfo;
import com.zeroone.star.project.j3.sortallocation.dto.CategoryDTO;
import com.zeroone.star.project.j3.sortallocation.vo.CategoryVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author jungle
 * @since 2024-10-20
 */
public interface ICmsCategoryinfoService extends IService<CmsCategoryinfo> {

    /*
    查询分类列表
    * */
    List<CategoryVO> listAll(String appId);

    //修改栏目分类
    CategoryDTO updateCategory(CategoryDTO categoryDTO);

    //添加栏目分类
    String updateCategory(String name, String appId);

    //删除栏目分类
    Boolean removeCategorybyId(String id);
}
