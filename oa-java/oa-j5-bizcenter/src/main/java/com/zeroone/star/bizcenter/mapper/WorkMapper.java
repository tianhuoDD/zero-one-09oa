package com.zeroone.star.bizcenter.mapper;

import org.apache.ibatis.annotations.Select;

import javax.annotation.Resource;

@Resource
public interface WorkMapper {

    @Select("SELECT xjob FROM pp_c_work WHERE xid = #{xid}")
    String selectXjobByXid(String xid);
}
