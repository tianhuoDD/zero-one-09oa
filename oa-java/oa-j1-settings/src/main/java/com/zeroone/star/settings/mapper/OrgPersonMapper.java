package com.zeroone.star.settings.mapper;

import com.zeroone.star.project.dto.j1.settings.SaveInfoDTO;
import com.zeroone.star.settings.entity.OrgPerson;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.Date;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author juhao
 * @since 2024-10-21
 */
@Mapper
public interface OrgPersonMapper extends BaseMapper<OrgPerson> {

    @Select("select xpassword from org_person where xid = #{id}")
    String selectPasswordById(String id);

    @Update("update org_person set xpassword=#{password} where xid=#{id}")
    void updatePassword(String password, String id);

    void updatePersonInfo(SaveInfoDTO data);

    @Update("update org_person set xchangePasswordTime=#{changePasswordTime} where xid=#{id}")
    void updateChangePasswordTime(Date changePasswordTime, String id);

    @Update("update org_person set xupdateTime=#{updateTime} where xid=#{id}")
    void updateUpdateTime(Date updateTime, String id);
}
