package com.zeroone.star.login.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.login.entity.OrgRole;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface OrgRoleMapper extends BaseMapper<OrgRole> {
	List<String> getRolesByUserId(String id);
}
