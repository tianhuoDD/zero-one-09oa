package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.OrgIdentity;
import com.zeroone.star.bizcenter.entity.OrgPerson;

public interface IOrgPersonService {

    /**
     * 根据用户id获取信息
     * @param id 用户id
     * @return
     */
    public OrgPerson getOrgIdentityById(String id) ;
}
