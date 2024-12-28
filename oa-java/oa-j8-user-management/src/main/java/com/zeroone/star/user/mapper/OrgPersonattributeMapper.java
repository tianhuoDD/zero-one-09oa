package com.zeroone.star.user.mapper;

import com.zeroone.star.project.dto.j8.user.user_attributes.UserAttributesDTO;
import com.zeroone.star.project.dto.j8.user.user_attributes.UserAttributesDTO1;
import com.zeroone.star.user.entity.OrgPersonattribute;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_personattribute】的数据库操作Mapper
 * @createDate 2024-10-24 20:49:30
 * @Entity com.zeroone.star.user.entity.OrgPersonattribute
 */
@Mapper
public interface OrgPersonattributeMapper extends BaseMapper<OrgPersonattribute> {

    ArrayList<UserAttributesDTO1> queryById(@Param("personId") String personId);

    void deleteByXIds(@Param("xIdList") List<String> xIdList);
}




