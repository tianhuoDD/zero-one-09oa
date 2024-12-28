package com.zeroone.star.cmshome.service.impl;

import com.zeroone.star.cmshome.entity.OrgUnit;
import com.zeroone.star.cmshome.mapper.OrgUnitMapper;
import com.zeroone.star.cmshome.service.IOrgUnitService;
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
public class OrgUnitServiceImpl extends ServiceImpl<OrgUnitMapper, OrgUnit> implements IOrgUnitService {

    @Override
    public OrgUnit queryById(String xid) {
        return baseMapper.selectById(xid);
    }
}
