package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.OrgIdentity;

public interface IOrgIdentityService {
    /**
     * 根据用户id获取身份信息
     * @param personId 用户id
     * @return
     */
    public OrgIdentity getOrgIdentityByPersonId(String personId) ;


}
