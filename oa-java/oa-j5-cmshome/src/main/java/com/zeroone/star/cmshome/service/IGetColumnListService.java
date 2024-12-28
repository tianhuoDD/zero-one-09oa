package com.zeroone.star.cmshome.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.cmshome.GetColumnListDTO;
import com.zeroone.star.project.query.j5.cmshome.GetColumnList;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnListVO;

/**
 * <p>
 * 描述：获取栏目列表
 * </p>
 * @author 陈思蒙
 */
public interface IGetColumnListService extends IService<GetColumnList> {

    PageDTO<GetColumnListVO> page(GetColumnListDTO getColumnListDTO);
}
