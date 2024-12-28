package com.zeroone.star.user.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.j8.user.user.UserQuery;
import com.zeroone.star.user.entity.OrgPerson;
import java.util.List;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

@Mapper
public interface OrgPersonMapper extends BaseMapper<OrgPerson> {

    /**
     * 根据条件查询用户列表
     *
     * @param page 用户名称（可选条件）
     * @return 用户DTO列表
     */
    List<OrgPerson> getPersonList(Page<OrgPerson> page, @Param("query") UserQuery query);

}
