package com.zeroone.star.bizcenter.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.CmsCategoryInfo;
import com.zeroone.star.bizcenter.mapper.CmsCategoryInfoMapper;
import com.zeroone.star.bizcenter.service.CmsCategoryInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CmsCategoryInfoServiceImpl  extends ServiceImpl<CmsCategoryInfoMapper, CmsCategoryInfo> implements CmsCategoryInfoService {

    @Autowired
    private CmsCategoryInfoMapper cmsCategoryInfoMapper;


    /**
     * 根据应用id 查找 分类信息
     * @param appId 应用id
     * @return 分类信息
     */
    @Override
    public List<CmsCategoryInfo> listProcessListByAppId(String appId) {
        QueryWrapper<CmsCategoryInfo> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("xappId",appId);
        List<CmsCategoryInfo> cmsCategoryInfos = cmsCategoryInfoMapper.selectList(queryWrapper);
        if (cmsCategoryInfos.isEmpty()){
            throw new RuntimeException("分类信息为空");
        }
        return cmsCategoryInfos;
    }
}
