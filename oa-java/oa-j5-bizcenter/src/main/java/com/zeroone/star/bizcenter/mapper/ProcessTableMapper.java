package com.zeroone.star.bizcenter.mapper;


import com.zeroone.star.project.vo.j5.bizcenter.formData.Form;
import org.apache.ibatis.annotations.Select;

import javax.annotation.Resource;


@Resource
public interface ProcessTableMapper {

    /**
     * 根据id获取表单格式
     * @param xid
     * @return
     */
    @Select("SELECT xname , xalias , xcategory,xapplication,xhasMobile,xdata from pp_e_form where xid = #{xid}")
    Form selectTableByXid(String xid);

}
