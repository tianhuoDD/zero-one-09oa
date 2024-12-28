package com.zeroone.star.cmshome.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j5.cmshome.GetColumnListDTO;
import com.zeroone.star.project.query.j5.cmshome.GetColumnList;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 描述：获取栏目列表
 * </p>
 * @author 陈思蒙
 */
@Mapper
public interface GetColumnListMapper extends BaseMapper<GetColumnList> {

    /**
     * 查询栏目列表（条件 + 分页）
     * @param getColumnListDTO 获取栏目列表请求实体类
     * @return 栏目列表集合
     */
    List<GetColumnList> getColumnList(GetColumnListDTO getColumnListDTO);
}
