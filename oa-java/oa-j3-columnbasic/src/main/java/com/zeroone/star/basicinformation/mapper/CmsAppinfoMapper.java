package com.zeroone.star.basicinformation.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.basicinformation.entity.CmsAppinfo;
import com.zeroone.star.project.j3.appinfo.dto.AppTypeDTO;
import com.zeroone.star.project.j3.columnbasicinformation.dto.BasicinformationDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import javax.validation.constraints.NotBlank;
import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 */
@Mapper
public interface CmsAppinfoMapper extends BaseMapper<CmsAppinfo> {
    List<AppTypeDTO> selectAppTypeList();
   // Page<CmsAppinfo> selectApp(@Param("condition") AppQuery condition, Page page);
    BasicinformationDTO basicinformation(@NotBlank String xid);

    void updateId(CmsAppinfo appinfo);

    List<String> queryform(@NotBlank String xid);

    @Select("select * from cms_appinfo where xid = #{xid}")
    CmsAppinfo getById(String xid);
    // Page<CmsAppinfo> selectApp(@Param("condition") AppQuery condition, Page page);
}
