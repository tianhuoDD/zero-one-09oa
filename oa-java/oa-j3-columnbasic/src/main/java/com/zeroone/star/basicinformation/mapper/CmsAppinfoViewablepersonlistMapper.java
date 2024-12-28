package com.zeroone.star.basicinformation.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.basicinformation.entity.CmsAppinfoViewablepersonlist;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author KO
 */
@Mapper
public interface CmsAppinfoViewablepersonlistMapper extends BaseMapper<CmsAppinfoViewablepersonlist> {
    @Select("SELECT xviewablePersonList FROM zo_oa.cms_appinfo_viewablepersonlist where APPINFO_XID=#{xid}")
    List<String> selectById(String id);
    @Update("update cms_appinfo_viewablepersonlist set xviewablePersonList = #{xviewablePersonList} where APPINFO_XID = #{xid}")
    void updateView(String xid, String xviewablePersonList);

    @Delete("delete from cms_appinfo_viewablepersonlist where APPINFO_XID = #{xid}")
    void deleteById(String xid);
}
