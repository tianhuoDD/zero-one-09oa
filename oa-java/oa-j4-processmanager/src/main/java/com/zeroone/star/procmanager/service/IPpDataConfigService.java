package com.zeroone.star.procmanager.service;

import com.zeroone.star.project.dto.j4.procmanager.AddDataConfigDto.AddDataConfigDto;
import com.zeroone.star.project.dto.j4.procmanager.UpdateDataConfigDto.UpdateDataConfigDto;
import com.zeroone.star.project.dto.j4.procmanager.DeleteDataConfigDto.DeleteDataConfigDto;
import com.zeroone.star.project.dto.j4.procmanager.data.properties.CategoryDTO;
import com.zeroone.star.project.dto.j4.procmanager.data.properties.DetailedConfigurationDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.procmanager.AddApplicationVo.AddDataConfigVo;
import com.zeroone.star.project.vo.j4.procmanager.UpdateDataConfigVo.UpdateDataConfigVo;
import com.zeroone.star.project.vo.j4.procmanager.DeleteDataConfigVo.DeleteDataConfigVo;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.CategoryVO;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.DetailedConfigurationVO;

import java.util.List;

/**
 * <p>
 * 数据配置服务接口
 * </p>
 *
 * @author j4
 * @since 2024-10-28
 */
public interface IPpDataConfigService {
    AddDataConfigVo addDataConfig(AddDataConfigDto dto);

    UpdateDataConfigVo updateDataConfig(UpdateDataConfigDto dto);

    DeleteDataConfigVo deleteDataConfig(DeleteDataConfigDto dto);

    JsonVO<List<CategoryVO>> queryCategoryAll(CategoryDTO categoryDTO);

    JsonVO<DetailedConfigurationVO> queryDataAll(DetailedConfigurationDTO dto);
}