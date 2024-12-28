package com.zeroone.star.procmanager.service;

import com.zeroone.star.project.dto.j4.procmanager.data.properties.DetailedConfigurationDTO;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.DetailedConfigurationVO;

import java.util.List;

public interface DetailedConfigurationService {
    List<DetailedConfigurationVO> queryDataAll(DetailedConfigurationDTO detailedConfigurationDTO);
}
