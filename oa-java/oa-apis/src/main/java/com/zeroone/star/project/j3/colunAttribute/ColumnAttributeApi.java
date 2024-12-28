package com.zeroone.star.project.j3.colunAttribute;

import com.zeroone.star.project.j3.ColumnAttribute.dto.ColumnAttributeDTO;
import com.zeroone.star.project.j3.ColumnAttribute.vo.ColumnAttributeVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @Program: zero-one-09oa   //名称
 * @ClassName : ColumnFormApis  //类名
 * @Author: lenyan   /作者
 * @Date: 2024/10/15  23:42
 **/
public interface ColumnAttributeApi {
    /**
     * 查询栏目属性
     * @param id
     * @return
     */
    public JsonVO<ColumnAttributeVO> queryColumnAttribute(String id);

    /**
     * 更新栏目属性
     * @param cmsFormDTOList
     * @return
     */
    public JsonVO<Boolean> modifyColumnAttribute(ColumnAttributeDTO cmsFormDTOList);
}
