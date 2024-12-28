package com.zeroone.star.user.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.user.entity.OrgUnitdutyIdentitylist;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_unitduty_identitylist】的数据库操作Mapper
 * @createDate 2024-10-24 20:49:30
 * @Entity com.zeroone.star.user.entity.OrgUnitdutyIdentitylist
 */
@Mapper
public interface OrgUnitdutyIdentitylistMapper extends BaseMapper<OrgUnitdutyIdentitylist> {
    /**
     * 根据xidentityList查询UNITDUTY_XID
     */
    @Select("SELECT UNITDUTY_XID FROM org_unitduty_identitylist WHERE xidentityList = #{xidentityList}")
    String selectUnitdutyXidByXidentityList(@Param("xidentityList") String xidentityList);
}




