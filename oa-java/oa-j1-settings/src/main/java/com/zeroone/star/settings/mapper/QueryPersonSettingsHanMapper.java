package com.zeroone.star.settings.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.settings.entity.OrgPerson;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Service;

@Mapper
public interface QueryPersonSettingsHanMapper extends BaseMapper<OrgPerson> {

    @Select("select xid, xlanguage, xmail, xmobile, xname, xofficePhone, xqq, xweixin, xsignature, xemployee, xnickName, xipAddress from org_person where xid = #{id}")
    public OrgPerson getOrgPersonById(String id);
}
