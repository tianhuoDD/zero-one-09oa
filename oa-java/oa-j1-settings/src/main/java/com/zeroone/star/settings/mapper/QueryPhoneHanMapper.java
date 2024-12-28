package com.zeroone.star.settings.mapper;

import com.zeroone.star.settings.entity.OrgPerson;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

@Mapper
public interface QueryPhoneHanMapper {
    @Select("select xmobile from org_person where xid = #{id}")
    public OrgPerson queryPhoneHan(String id);
}
