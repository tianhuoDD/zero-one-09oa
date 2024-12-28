package com.zeroone.star.user.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.user.entity.OrgUnitduty;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_unitduty】的数据库操作Mapper
 * @createDate 2024-10-24 20:49:30
 * @Entity com.zeroone.star.user.entity.OrgUnitduty
 */
@Mapper
public interface OrgUnitdutyMapper extends BaseMapper<OrgUnitduty> {
    @Select("SELECT xname from org_unitduty WHERE xid = #{xid}")
    String getXnameByDutyId(@Param("xid") String dutyId);
}




