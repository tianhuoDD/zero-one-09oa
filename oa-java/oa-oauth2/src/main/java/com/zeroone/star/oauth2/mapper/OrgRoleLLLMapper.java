package com.zeroone.star.oauth2.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;

import com.zeroone.star.oauth2.entity.OrgRole;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;
@Transactional
@Mapper
public interface OrgRoleLLLMapper extends BaseMapper<OrgRole> {


    /**
     * 根据菜单id查询角色
     * @param orgRoleIds 角色id集合
     * @return
     */
    List<OrgRole> listRoleById(List<String> orgRoleIds);

    /**
     * 根据用户id查询角色
     * @param personXid 用户id
     * @return
     */
    List<OrgRole> listRoleByUserId(String personXid);

}
