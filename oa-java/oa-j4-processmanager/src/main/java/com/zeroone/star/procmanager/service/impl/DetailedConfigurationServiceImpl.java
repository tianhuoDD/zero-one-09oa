package com.zeroone.star.procmanager.service.impl;

import com.zeroone.star.procmanager.mapper.DetailedConfigurationMapper;
import com.zeroone.star.procmanager.service.DetailedConfigurationService;
import com.zeroone.star.project.dto.j4.procmanager.data.properties.DetailedConfigurationDTO;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.DetailedConfigurationVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class DetailedConfigurationServiceImpl implements DetailedConfigurationService {
    @Resource
    private DetailedConfigurationMapper detailedConfigurationMapper;



    @Override
    public List<DetailedConfigurationVO> queryDataAll(DetailedConfigurationDTO detailedConfigurationDTO) {
            List<DetailedConfigurationVO> detailedConfigurationVO = detailedConfigurationMapper.queryDataAll(detailedConfigurationDTO);
        return detailedConfigurationVO;
    }
}
