package com.zeroone.star.basicinformation.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.basicinformation.entity.CmsAppinfoManageablepersonlist;
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
public interface CmsAppinfoManageablepersonlistMapper extends BaseMapper<CmsAppinfoManageablepersonlist> {

    @Select("SELECT xmanageablePersonList FROM zo_oa.cms_appinfo_manageablepersonlist")
    List<String> selectById(String id);

    @Update("update cms_appinfo_manageablepersonlist set xmanageablePersonList = #{xmanageablePersonList} where APPINFO_XID = #{xid}")
    void updateManageablePersonList(String xid, String xmanageablePersonList);
    @Delete("delete from cms_appinfo_manageablepersonlist where APPINFO_XID = #{xid}")
    void deleteById(String xid);
}
