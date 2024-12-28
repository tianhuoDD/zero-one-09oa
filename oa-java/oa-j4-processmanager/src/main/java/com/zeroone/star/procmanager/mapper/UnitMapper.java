package com.zeroone.star.procmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.procmanager.entity.OrgUnit;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 * 描述：
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author nefertari
 * @version 1.0.0
 */
@Mapper
public interface UnitMapper extends BaseMapper<OrgUnit> {
    /**
     * 通过id查询组织
     * @param id
     * @return
     */
    String selectUnitNameById(@Param("xid") String id);
}
