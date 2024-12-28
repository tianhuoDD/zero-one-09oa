package com.zeroone.star.systemhome.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.systemhome.entity.file.MtBuilding;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  mapper接口，对应mt_building表格，MtBuilding实体类
 * </p>
 *
 * @author j1.rabbit
 * @since 2024-10-27
 */
@Mapper
public interface MtBuildingMapper extends BaseMapper<MtBuilding> {
}
