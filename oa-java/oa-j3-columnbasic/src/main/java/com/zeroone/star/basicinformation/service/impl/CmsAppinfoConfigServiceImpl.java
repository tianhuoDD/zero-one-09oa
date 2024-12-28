package com.zeroone.star.basicinformation.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.basicinformation.entity.CmsAppinfoConfig;
import com.zeroone.star.basicinformation.mapper.CmsAppinfoConfigMapper;
import com.zeroone.star.basicinformation.service.ICmsAppinfoConfigService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.columnbasicinformation.dto.AppinfoConfigDTO;
import com.zeroone.star.project.j3.columnbasicinformation.dto.AppinfoDTO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author Kokoro
 * @since 2024-10-20
 */
@Service
@Transactional
public class CmsAppinfoConfigServiceImpl extends ServiceImpl<CmsAppinfoConfigMapper, CmsAppinfoConfig> implements ICmsAppinfoConfigService {

    @Resource
    CmsAppinfoConfigMapper cmsAppinfoConfigMapper;

    @Override
    public Integer addColumnConfig(AppinfoConfigDTO appinfoConfigDTO) {
        CmsAppinfoConfig cmsAppinfoConfig = BeanUtil.toBean(appinfoConfigDTO, CmsAppinfoConfig.class);
        Integer result = cmsAppinfoConfigMapper.insert(cmsAppinfoConfig);
        return result;
    }

    @Override
    public Integer deleteColumnConfig(String xid) {
        QueryWrapper<CmsAppinfoConfig> wrapper = new QueryWrapper<>();
        wrapper.eq("xid", xid);
        Integer result = cmsAppinfoConfigMapper.delete(wrapper);
        return result;
    }
}
