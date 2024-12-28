package com.zeroone.star.basicinformation.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.basicinformation.entity.CmsAppinfoPublishablepersonlist;
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
public interface CmsAppinfoPublishablepersonlistMapper extends BaseMapper<CmsAppinfoPublishablepersonlist> {

    @Select("SELECT xpublishablePersonList FROM zo_oa.cms_appinfo_publishablepersonlist where APPINFO_XID=#{xid}")
    List<String> selectById(String xid);

    @Update("update cms_appinfo_publishablepersonlist set xpublishablePersonList = #{xpublishablePersonList} where APPINFO_XID = #{xid}")
    void updatePublishablePersonList(String xid, String xpublishablePersonList);

    @Delete("delete from cms_appinfo_publishablepersonlist where APPINFO_XID = #{xid}")
    void deleteById(String xid);
}
