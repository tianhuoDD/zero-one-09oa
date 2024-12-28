package com.zeroone.star.oaj2sysbasic.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oaj2sysbasic.entity.FormTemplate;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;


@Mapper
public interface TemplateMapper extends BaseMapper<FormTemplate> {

    @Insert("insert into qry_import_model(xid, xdata, xdescription, xname, xcreateTime, xupdateTime, xtype, xdisplay,xdistributeFactor,xalias)" +
            " VALUES" +
            " (#{xid}, #{xdata}, #{xdescription}, #{xname}, #{xcreateTime}, #{xupdateTime}, #{xtype}, #{xdisplay},#{xdistributeFactor},#{alias})")
    void insetTemplate(FormTemplate formTemplate);

    void updateformTemplate(FormTemplate formTemplate);
}
