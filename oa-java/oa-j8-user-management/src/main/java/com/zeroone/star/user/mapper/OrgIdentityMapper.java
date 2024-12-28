package com.zeroone.star.user.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.j8.user.user_identity.UserIdentityQuery;
import com.zeroone.star.user.entity.OrgIdentity;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_identity】的数据库操作Mapper
 * @createDate 2024-10-24 20:49:30
 * @Entity com.zeroone.star.user.entity.OrgIdentity
 */
@Mapper
public interface OrgIdentityMapper extends BaseMapper<OrgIdentity> {

    /**
     * 分页查询用户身份
     * @param page 分页对象
     * @param query 查询条件
     * @return 用户身份列表
     */
    @Select("SELECT * FROM org_identity WHERE xperson = #{query.xperson}")
    IPage<OrgIdentity> getIdentityList(Page<OrgIdentity> page, @Param("query") UserIdentityQuery query);
}




