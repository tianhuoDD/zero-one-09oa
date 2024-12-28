package com.zeroone.star.procmanager.mapper;

import com.zeroone.star.project.dto.j4.procmanager.data.properties.DetailedConfigurationDTO;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.DetailedConfigurationVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface DetailedConfigurationMapper {


//    @Select("select xbooleanValue,xnumberValue,xstringShortValue from PP_E_APPLICATIONDICTITEM where xbundle=#{xbundle}")
    List<DetailedConfigurationVO> queryDataAll(DetailedConfigurationDTO detailedConfigurationDTO);
}
