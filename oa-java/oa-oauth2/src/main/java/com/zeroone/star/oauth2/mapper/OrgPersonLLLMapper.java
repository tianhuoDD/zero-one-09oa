package com.zeroone.star.oauth2.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oauth2.entity.OrgPerson;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface OrgPersonLLLMapper extends BaseMapper<OrgPerson> {



    OrgPerson getPersonByName(String Xname);
}
