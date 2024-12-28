package com.zeroone.star.bizcenter.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.OrgIdentity;
import com.zeroone.star.bizcenter.mapper.OrgIdentityMapper;
import com.zeroone.star.bizcenter.service.IOrgIdentityService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class OrgIdentityServiceImpl extends ServiceImpl<OrgIdentityMapper, OrgIdentity> implements IOrgIdentityService {

    @Autowired
    private OrgIdentityMapper orgIdentityMapper;

    /**
     * 根据用户id获取身份信息
     * @param personId 用户id
     * @return
     */
    @Override
    public OrgIdentity getOrgIdentityByPersonId(String personId) {
        QueryWrapper<OrgIdentity> queryWrapper = new QueryWrapper();
        queryWrapper.eq("xperson",personId);
        return orgIdentityMapper.selectOne(queryWrapper);
    }


}
