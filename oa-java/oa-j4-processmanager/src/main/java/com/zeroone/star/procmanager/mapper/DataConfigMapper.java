package com.zeroone.star.procmanager.mapper;

import com.zeroone.star.project.dto.j4.procmanager.data.properties.CategoryDTO;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.CategoryVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.springframework.web.bind.annotation.GetMapping;
import java.util.List;

@Mapper
public interface DataConfigMapper {

//    @Select("select * from PP_E_APPLICATIONDICT")
    List<CategoryVO> queryCategoryAll(CategoryDTO categoryDTO);
}
