package com.zeroone.star.basicinformation.mapper;

import com.zeroone.star.basicinformation.entity.CmsAppinfoConfig;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author Kokoro
 * @since 2024-10-20
 */
@Mapper
public interface CmsAppinfoConfigMapper extends BaseMapper<CmsAppinfoConfig> {

    @Select("select * from cms_appinfo_config where xid = #{id}")
    CmsAppinfoConfig selectByXid(String id);
}
