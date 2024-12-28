package com.zeroone.star.cmshome.service.impl;

import com.zeroone.star.cmshome.entity.OrgIdentity;
import com.zeroone.star.cmshome.mapper.OrgIdentityMapper;
import com.zeroone.star.cmshome.service.IOrgIdentityService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-25
 */
@Service
public class OrgIdentityServiceImpl extends ServiceImpl<OrgIdentityMapper, OrgIdentity> implements IOrgIdentityService {

    @Override
    public OrgIdentity queryOrgIdentity(String xid) {
        return baseMapper.selectById(xid);
    }
}
