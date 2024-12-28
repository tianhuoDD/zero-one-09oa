package com.zeroone.star.bizcenter.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.OrgIdentity;
import com.zeroone.star.bizcenter.entity.OrgPerson;
import com.zeroone.star.bizcenter.mapper.OrgIdentityMapper;
import com.zeroone.star.bizcenter.mapper.OrgPersonMapper;
import com.zeroone.star.bizcenter.service.IOrgIdentityService;
import com.zeroone.star.bizcenter.service.IOrgPersonService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class OrgPersonServiceImpl extends ServiceImpl<OrgPersonMapper, OrgPerson> implements IOrgPersonService {

    @Autowired
    private OrgPersonMapper orgPersonMapper;
    /**
     * 根据用户id获取信息
     * @param id 用户id
     * @return
     */
    @Override
    public OrgPerson getOrgIdentityById(String id) {
        return orgPersonMapper.selectById(id);
    }
}
