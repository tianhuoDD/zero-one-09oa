package com.zeroone.star.project.j5.cmshome;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnCategoryVO;

import java.util.List;

/**
 * <p>
 * 描述：获取所有栏目类型接口
 * </p>
 * @author 陈思蒙
 */
public interface GetColumnCategoryApis {

    /**
     * 获取栏目类型
     * @param id 用户id
     * @return 栏目类型集合
     */
    JsonVO<List<GetColumnCategoryVO>> getColumnCategory();
}
