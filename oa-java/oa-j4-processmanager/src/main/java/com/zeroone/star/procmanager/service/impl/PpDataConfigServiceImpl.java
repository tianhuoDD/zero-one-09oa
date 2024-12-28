package com.zeroone.star.procmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.zeroone.star.procmanager.mapper.PpDataConfigMapper;
import com.zeroone.star.procmanager.service.IPpDataConfigService;
import com.zeroone.star.project.dto.j4.procmanager.AddDataConfigDto.AddDataConfigDto;
import com.zeroone.star.project.dto.j4.procmanager.UpdateDataConfigDto.UpdateDataConfigDto;
import com.zeroone.star.project.dto.j4.procmanager.DeleteDataConfigDto.DeleteDataConfigDto;
import com.zeroone.star.project.dto.j4.procmanager.data.properties.CategoryDTO;
import com.zeroone.star.project.dto.j4.procmanager.data.properties.DetailedConfigurationDTO;
import com.zeroone.star.procmanager.entity.PpDataConfig;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.procmanager.AddApplicationVo.AddDataConfigVo;
import com.zeroone.star.project.vo.j4.procmanager.UpdateDataConfigVo.UpdateDataConfigVo;
import com.zeroone.star.project.vo.j4.procmanager.DeleteDataConfigVo.DeleteDataConfigVo;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.CategoryVO;
import com.zeroone.star.project.vo.j4.procmanager.data.properties.DetailedConfigurationVO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class PpDataConfigServiceImpl implements IPpDataConfigService {

    @Resource
    private PpDataConfigMapper ppDataConfigMapper;

    @Resource
    private ObjectMapper objectMapper;

    @Override
    @Transactional
    public AddDataConfigVo addDataConfig(AddDataConfigDto dto) {
        // 参数校验
        if (dto == null || dto.getName() == null) {
            throw new IllegalArgumentException("名称不能为空");
        }

        // DTO转实体
        PpDataConfig dataConfig = new PpDataConfig();
        BeanUtils.copyProperties(dto, dataConfig);

        try {
            // 处理 JSON 字段
            dataConfig
                    .setFormList(dto.getFormList() != null ? objectMapper.writeValueAsString(dto.getFormList()) : "[]");
            dataConfig.setProcessList(
                    dto.getProcessList() != null ? objectMapper.writeValueAsString(dto.getProcessList()) : "[]");

            // 保存到数据库
            ppDataConfigMapper.insert(dataConfig);

            // 构建返回对象
            AddDataConfigVo result = new AddDataConfigVo();
            BeanUtils.copyProperties(dataConfig, result);
            result.setFormList(objectMapper.readValue(dataConfig.getFormList(),
                    new TypeReference<List<String>>() {
                    }));
            result.setProcessList(objectMapper.readValue(dataConfig.getProcessList(),
                    new TypeReference<List<String>>() {
                    }));

            return result;
        } catch (Exception e) {
            throw new RuntimeException("数据处理失败", e);
        }
    }

    @Override
    @Transactional
    public UpdateDataConfigVo updateDataConfig(UpdateDataConfigDto dto) {
        // 参数校验
        if (dto == null || dto.getId() == null) {
            throw new IllegalArgumentException("ID不能为空");
        }

        // 检查存在性
        PpDataConfig dataConfig = ppDataConfigMapper.selectById(dto.getId());
        if (dataConfig == null) {
            throw new IllegalArgumentException("数据配置不存在");
        }

        // 更新数据
        BeanUtils.copyProperties(dto, dataConfig);
        try {
            dataConfig
                    .setFormList(dto.getFormList() != null ? objectMapper.writeValueAsString(dto.getFormList()) : "[]");
            dataConfig.setProcessList(
                    dto.getProcessList() != null ? objectMapper.writeValueAsString(dto.getProcessList()) : "[]");
        } catch (Exception e) {
            throw new RuntimeException("数据处理失败", e);
        }
        ppDataConfigMapper.updateById(dataConfig);

        // 构建返回对象
        UpdateDataConfigVo result = new UpdateDataConfigVo();
        BeanUtils.copyProperties(dataConfig, result);
        try {
            result.setFormList(objectMapper.readValue(dataConfig.getFormList(),
                    new TypeReference<List<String>>() {
                    }));
            result.setProcessList(objectMapper.readValue(dataConfig.getProcessList(),
                    new TypeReference<List<String>>() {
                    }));
        } catch (Exception e) {
            throw new RuntimeException("JSON处理失败", e);
        }

        return result;
    }

    @Override
    @Transactional
    public DeleteDataConfigVo deleteDataConfig(DeleteDataConfigDto dto) {
        // 参数校验
        if (dto == null || dto.getId() == null) {
            throw new IllegalArgumentException("ID不能为空");
        }

        // 检查存在性
        PpDataConfig dataConfig = ppDataConfigMapper.selectById(dto.getId());
        if (dataConfig == null) {
            throw new IllegalArgumentException("数据配置不存在");
        }

        // 删除数据
        ppDataConfigMapper.deleteById(dto.getId());

        // 构建返回对象
        DeleteDataConfigVo result = new DeleteDataConfigVo();
        result.setId(dto.getId());
        return result;
    }

    @Override
    public JsonVO<List<CategoryVO>> queryCategoryAll(CategoryDTO categoryDTO) {
        // 构建查询条件
        QueryWrapper<PpDataConfig> queryWrapper = new QueryWrapper<>();
        if (categoryDTO != null && categoryDTO.getXname() != null) {
            queryWrapper.eq("name", categoryDTO.getXname().trim());
        }

        // 查询数据
        List<PpDataConfig> dataConfigs = ppDataConfigMapper.selectList(queryWrapper);

        // 转换为VO对象
        List<CategoryVO> categoryVOs = dataConfigs.stream().map(config -> {
            CategoryVO vo = new CategoryVO();
            vo.setXname(config.getName());
            vo.setIcon(config.getIcon());
            return vo;
        }).collect(Collectors.toList());

        return JsonVO.success(categoryVOs);
    }

    @Override
    public JsonVO<DetailedConfigurationVO> queryDataAll(DetailedConfigurationDTO dto) {
        // 构建查询条件
        QueryWrapper<PpDataConfig> queryWrapper = new QueryWrapper<>();
        if (dto != null && dto.getXname() != null) {
            queryWrapper.eq("name", dto.getXname().trim());
        }

        // 查询数据
        PpDataConfig dataConfig = ppDataConfigMapper.selectOne(queryWrapper);

        // 转换为VO对象
        DetailedConfigurationVO vo = new DetailedConfigurationVO();
        if (dataConfig != null) {
            // 正确映射字段名
            vo.setXname(dataConfig.getName());
            vo.setAlias(dataConfig.getAlias());
            vo.setXdescription(dataConfig.getDescription());
        }

        return JsonVO.success(vo);
    }
}