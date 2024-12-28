package com.zeroone.star.cmshome.mapper;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.cmshome.entity.CmsDocument;
import com.zeroone.star.cmshome.entity.QryItem;
import org.apache.ibatis.annotations.Mapper;

/**
 * 发布消息接口
 * @author：wxf
 * @since 2024-10-25
 */
@Mapper
public interface QryItemMapper extends BaseMapper<QryItem> {

}
