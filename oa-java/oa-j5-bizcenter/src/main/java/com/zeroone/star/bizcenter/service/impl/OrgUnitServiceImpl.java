package com.zeroone.star.bizcenter.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.OrgPerson;
import com.zeroone.star.bizcenter.entity.OrgUnit;
import com.zeroone.star.bizcenter.mapper.OrgPersonMapper;
import com.zeroone.star.bizcenter.mapper.OrgUnitMapper;
import com.zeroone.star.bizcenter.service.IOrgPersonService;
import com.zeroone.star.bizcenter.service.IOrgUnitService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class OrgUnitServiceImpl  extends ServiceImpl<OrgUnitMapper, OrgUnit> implements IOrgUnitService {

    @Autowired
    private OrgUnitMapper orgUnitMapper;
    /**
     * 根据用户id获取信息
     * @param id 用户id
     * @return
     */
    @Override
    public OrgUnit getOrgUnitById(String id) {
        return orgUnitMapper.selectById(id);
    }
}
