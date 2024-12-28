package com.zeroone.star.cmshome.service.impl;

import com.zeroone.star.cmshome.entity.OrgPerson;
import com.zeroone.star.cmshome.mapper.OrgPersonMapper;
import com.zeroone.star.cmshome.service.IOrgPersonService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-28
 */
@Service
public class OrgPersonServiceImpl extends ServiceImpl<OrgPersonMapper, OrgPerson> implements IOrgPersonService {

    @Override
    public OrgPerson queryById(String xid) {
        return baseMapper.selectById(xid);
    }
}
