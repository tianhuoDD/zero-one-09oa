package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.entity.OrgPerson;
import com.zeroone.star.oauth2.mapper.OrgPersonLLLMapper;
import com.zeroone.star.oauth2.service.OrgPersonLLLService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class OrgPersonLLLServiceImpl extends ServiceImpl<OrgPersonLLLMapper, OrgPerson> implements OrgPersonLLLService {
    /**
     * 根据用户名获取用户信息
     *
     * @param person
     * @return
     */
    @Resource
    OrgPersonLLLMapper orgPersonLLLMapper;

    @Override
    public OrgPerson getPersonByName(OrgPerson person) {
        if (person == null) {
            return null;
        }

        // 获取用户信息
        return orgPersonLLLMapper.getPersonByName(person.getXname());
    }
}
