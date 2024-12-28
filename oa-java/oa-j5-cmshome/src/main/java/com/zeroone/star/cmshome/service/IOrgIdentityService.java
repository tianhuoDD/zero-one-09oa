package com.zeroone.star.cmshome.service;

import com.zeroone.star.cmshome.entity.OrgIdentity;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-25
 */
public interface IOrgIdentityService extends IService<OrgIdentity> {

    /**
     * 根据id查询单位身份信息
     * @param xid 单位身份id
     * @return 单位身份信息
     */
    OrgIdentity queryOrgIdentity(String xid);
}
