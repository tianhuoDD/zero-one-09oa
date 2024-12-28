package com.zeroone.star.project.j5.cmshome;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.cmshome.GetColumnListDTO;
import com.zeroone.star.project.query.j5.cmshome.GetColumnListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnListVO;

/**
 * <p>
 * 描述：获取栏目列表接口
 * </p>
 *
 * @author 陈思蒙
 */
public interface GetColumnListApis {

    /**
     * 获取栏目列表
     *
     * @param getColumnListDTO 栏目信息（分页）
     * @return 栏目列表
     */
    JsonVO<PageDTO<GetColumnListVO>> getColumnList(GetColumnListDTO getColumnListDTO);
}
