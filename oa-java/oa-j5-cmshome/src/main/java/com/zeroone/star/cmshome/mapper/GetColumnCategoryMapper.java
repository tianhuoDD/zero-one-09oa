package com.zeroone.star.cmshome.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.query.j5.cmshome.GetColumnCategory;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnCategoryVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 描述：获取所有栏目类型
 * </p>
 * @author 陈思蒙
 */
@Mapper
public interface GetColumnCategoryMapper extends BaseMapper<GetColumnCategory> {

    @Select("select xappType as appType, count(xappType) as `count` from zo_oa.cms_appinfo group by xappType")
    List<GetColumnCategory> list();
}
