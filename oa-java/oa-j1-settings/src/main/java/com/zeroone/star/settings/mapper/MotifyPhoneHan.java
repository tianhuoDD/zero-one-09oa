package com.zeroone.star.settings.mapper;

import com.zeroone.star.project.dto.j1.person.setting.MotifyPhonehanDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Update;

@Mapper
public interface MotifyPhoneHan {
    @Update("update org_person set xmobile = #{newphone} where xid = #{id}")
    public int motigyPhone(MotifyPhonehanDTO motifyPhonehanDTO);
}
