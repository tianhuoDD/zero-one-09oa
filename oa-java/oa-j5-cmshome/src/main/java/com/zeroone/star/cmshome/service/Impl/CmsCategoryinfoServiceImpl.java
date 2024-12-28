package com.zeroone.star.cmshome.service.impl;

import com.zeroone.star.cmshome.entity.CmsCategoryinfo;
import com.zeroone.star.cmshome.mapper.CmsCategoryinfoMapper;
import com.zeroone.star.cmshome.service.ICmsCategoryinfoService;
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
public class CmsCategoryinfoServiceImpl extends ServiceImpl<CmsCategoryinfoMapper, CmsCategoryinfo> implements ICmsCategoryinfoService {

    @Override
    public CmsCategoryinfo queryCategory(String xid) {
        return baseMapper.selectById(xid);
    }
}
