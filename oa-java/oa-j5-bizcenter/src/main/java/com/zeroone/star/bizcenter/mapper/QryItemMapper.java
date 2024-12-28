package com.zeroone.star.bizcenter.mapper;

import com.zeroone.star.bizcenter.entity.QryItem;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-25
 */
@Mapper
public interface QryItemMapper extends BaseMapper<QryItem> {

    void saveItems(@Param("items") List<QryItem> items);
}
