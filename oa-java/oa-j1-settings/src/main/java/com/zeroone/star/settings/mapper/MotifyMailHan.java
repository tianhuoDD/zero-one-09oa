package com.zeroone.star.settings.mapper;

import com.zeroone.star.project.dto.j1.person.setting.MotifyMailhanDTO;
import com.zeroone.star.project.dto.j1.person.setting.MotifyPhonehanDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Update;

@Mapper
public interface MotifyMailHan {
    @Update("update org_person set xmail = #{newmail} where xid = #{id}")
    public int motigyMail(MotifyMailhanDTO motifyMailhanDTO);
}
