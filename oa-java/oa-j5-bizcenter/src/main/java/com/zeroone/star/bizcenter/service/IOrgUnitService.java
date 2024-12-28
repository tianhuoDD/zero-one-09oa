package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.OrgUnit;

public interface IOrgUnitService {

    /**
     * 根据id查询组织信息
     * @param id 组织id
     * @return
     */
    public OrgUnit getOrgUnitById(String id);
}
