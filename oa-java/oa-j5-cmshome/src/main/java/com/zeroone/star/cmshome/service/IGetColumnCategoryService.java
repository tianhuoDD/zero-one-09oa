package com.zeroone.star.cmshome.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.j5.cmshome.GetColumnCategory;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnCategoryVO;

import java.util.List;

/**
 * <p>
 * 描述：获取所有栏目类型
 * </p>
 * @author 陈思蒙
 */
public interface IGetColumnCategoryService extends IService<GetColumnCategory> {

    List<GetColumnCategoryVO> getColumnCategory();
}
